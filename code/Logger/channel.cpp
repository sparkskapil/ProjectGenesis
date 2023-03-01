#include "channel.h"
#include "driver.h"
#include "policy.h"

Channel::Channel(std::vector<std::shared_ptr<IDriver>> drivers /*= {}*/, std::vector<std::shared_ptr<IPolicy>> policies /*= {}*/)
{
    m_Drivers = drivers;
    m_Policies = policies;
}

void Channel::Submit(LogEntry& entry)
{
    for (auto& policy : m_Policies)
    {
        if (!policy->Evaluate(entry))
            return;
    }
    for (auto& driver : m_Drivers)
    {
        driver->Submit(entry);
    }
}

void Channel::AttachDriver(std::shared_ptr<IDriver> driver)
{
    m_Drivers.emplace_back(driver);
}

void Channel::AttachPolicy(std::shared_ptr<IPolicy> policy)
{
    m_Policies.emplace_back(policy);
}


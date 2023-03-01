#pragma once
#include <vector>
#include <memory>
#include "loggerinclude.h"
class IChannel
{
public:
    virtual ~IChannel() = default;
    virtual void Submit(LogEntry&) = 0;
    virtual void AttachDriver(std::shared_ptr<IDriver>) = 0;
    virtual void AttachPolicy(std::shared_ptr<IPolicy>) = 0;
};

class Channel: public IChannel
{
public:
    Channel(std::vector<std::shared_ptr<IDriver>> drivers = {}, std::vector<std::shared_ptr<IPolicy>> policies = {});
    ~Channel() = default;
    void Submit(LogEntry&) override;
    void AttachDriver(std::shared_ptr<IDriver>) override;
    void AttachPolicy(std::shared_ptr<IPolicy>) override;

private:
    std::vector<std::shared_ptr<IDriver>> m_Drivers;
    std::vector<std::shared_ptr<IPolicy>> m_Policies;
};
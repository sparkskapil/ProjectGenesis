WorkspaceRoot = "%{_WORKING_DIR}"
ProjectGenFolder = "%{WorkspaceRoot}/#projects"
OutputFolder ="%{WorkspaceRoot}/#build"
CodeFolder = "%{WorkspaceRoot}/code"
ExternFolder = "%{WorkspaceRoot}/extern"
VulkanSDK = os.getenv("VULKAN_SDK")
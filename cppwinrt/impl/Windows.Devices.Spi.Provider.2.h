// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200117.5

#ifndef WINRT_Windows_Devices_Spi_Provider_2_H
#define WINRT_Windows_Devices_Spi_Provider_2_H
#include "winrt/impl/Windows.Devices.Spi.Provider.1.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Spi::Provider
{
    struct __declspec(empty_bases) ProviderSpiConnectionSettings : Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings
    {
        ProviderSpiConnectionSettings(std::nullptr_t) noexcept {}
        ProviderSpiConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings(ptr, take_ownership_from_abi) {}
        explicit ProviderSpiConnectionSettings(int32_t chipSelectLine);
    };
}
#endif

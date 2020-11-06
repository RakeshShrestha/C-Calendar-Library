// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200117.5

#ifndef WINRT_Windows_Phone_Devices_Power_0_H
#define WINRT_Windows_Phone_Devices_Power_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename T> struct EventHandler;
    struct EventRegistrationToken;
}
WINRT_EXPORT namespace winrt::Windows::Phone::Devices::Power
{
    struct IBattery;
    struct IBatteryStatics;
    struct Battery;
}
namespace winrt::impl
{
    template <> struct category<Windows::Phone::Devices::Power::IBattery>{ using type = interface_category; };
    template <> struct category<Windows::Phone::Devices::Power::IBatteryStatics>{ using type = interface_category; };
    template <> struct category<Windows::Phone::Devices::Power::Battery>{ using type = class_category; };
    template <> inline constexpr auto& name_v<Windows::Phone::Devices::Power::Battery> = L"Windows.Phone.Devices.Power.Battery";
    template <> inline constexpr auto& name_v<Windows::Phone::Devices::Power::IBattery> = L"Windows.Phone.Devices.Power.IBattery";
    template <> inline constexpr auto& name_v<Windows::Phone::Devices::Power::IBatteryStatics> = L"Windows.Phone.Devices.Power.IBatteryStatics";
    template <> inline constexpr guid guid_v<Windows::Phone::Devices::Power::IBattery>{ 0x972ADBDD,0x6720,0x4702,{ 0xA4,0x76,0xB9,0xD3,0x8A,0x00,0x70,0xE3 } };
    template <> inline constexpr guid guid_v<Windows::Phone::Devices::Power::IBatteryStatics>{ 0xFAF5BC70,0x6369,0x11E1,{ 0xB8,0x6C,0x08,0x00,0x20,0x0C,0x9A,0x66 } };
    template <> struct default_interface<Windows::Phone::Devices::Power::Battery>{ using type = Windows::Phone::Devices::Power::IBattery; };
    template <> struct abi<Windows::Phone::Devices::Power::IBattery>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RemainingChargePercent(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RemainingDischargeTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall add_RemainingChargePercentChanged(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RemainingChargePercentChanged(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Phone::Devices::Power::IBatteryStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Phone_Devices_Power_IBattery
    {
        [[nodiscard]] WINRT_IMPL_AUTO(int32_t) RemainingChargePercent() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::TimeSpan) RemainingDischargeTime() const;
        WINRT_IMPL_AUTO(winrt::event_token) RemainingChargePercentChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& changeHandler) const;
        using RemainingChargePercentChanged_revoker = impl::event_revoker<Windows::Phone::Devices::Power::IBattery, &impl::abi_t<Windows::Phone::Devices::Power::IBattery>::remove_RemainingChargePercentChanged>;
        [[nodiscard]] RemainingChargePercentChanged_revoker RemainingChargePercentChanged(auto_revoke_t, Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& changeHandler) const;
        WINRT_IMPL_AUTO(void) RemainingChargePercentChanged(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::Phone::Devices::Power::IBattery>
    {
        template <typename D> using type = consume_Windows_Phone_Devices_Power_IBattery<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Devices_Power_IBatteryStatics
    {
        WINRT_IMPL_AUTO(Windows::Phone::Devices::Power::Battery) GetDefault() const;
    };
    template <> struct consume<Windows::Phone::Devices::Power::IBatteryStatics>
    {
        template <typename D> using type = consume_Windows_Phone_Devices_Power_IBatteryStatics<D>;
    };
}
#endif

// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200117.5

#ifndef WINRT_Windows_ApplicationModel_ExtendedExecution_Foreground_0_H
#define WINRT_Windows_ApplicationModel_ExtendedExecution_Foreground_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct IAsyncOperation;
    template <typename TSender, typename TResult> struct TypedEventHandler;
}
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::ExtendedExecution::Foreground
{
    enum class ExtendedExecutionForegroundReason : int32_t
    {
        Unspecified = 0,
        SavingData = 1,
        BackgroundAudio = 2,
        Unconstrained = 3,
    };
    enum class ExtendedExecutionForegroundResult : int32_t
    {
        Allowed = 0,
        Denied = 1,
    };
    enum class ExtendedExecutionForegroundRevokedReason : int32_t
    {
        Resumed = 0,
        SystemPolicy = 1,
    };
    struct IExtendedExecutionForegroundRevokedEventArgs;
    struct IExtendedExecutionForegroundSession;
    struct ExtendedExecutionForegroundRevokedEventArgs;
    struct ExtendedExecutionForegroundSession;
}
namespace winrt::impl
{
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>{ using type = interface_category; };
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>{ using type = interface_category; };
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs>{ using type = class_category; };
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession>{ using type = class_category; };
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason>{ using type = enum_category; };
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>{ using type = enum_category; };
    template <> struct category<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundRevokedEventArgs";
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundSession";
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundReason";
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundResult";
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundRevokedReason";
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.IExtendedExecutionForegroundRevokedEventArgs";
    template <> inline constexpr auto& name_v<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession> = L"Windows.ApplicationModel.ExtendedExecution.Foreground.IExtendedExecutionForegroundSession";
    template <> inline constexpr guid guid_v<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>{ 0xB07CD940,0x9557,0xAEA4,{ 0x2C,0x99,0xBD,0xD5,0x6D,0x9B,0xE4,0x61 } };
    template <> inline constexpr guid guid_v<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>{ 0xFBF440E1,0x9D10,0x4201,{ 0xB0,0x1E,0xC8,0x32,0x75,0x29,0x6F,0x2E } };
    template <> struct default_interface<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs>{ using type = Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs; };
    template <> struct default_interface<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession>{ using type = Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession; };
    template <> struct abi<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall add_Revoked(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Revoked(winrt::event_token) noexcept = 0;
            virtual int32_t __stdcall RequestExtensionAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Reason(int32_t) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundRevokedEventArgs
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason) Reason() const;
    };
    template <> struct consume<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundRevokedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundSession
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Description() const;
        WINRT_IMPL_AUTO(void) Description(param::hstring const& value) const;
        WINRT_IMPL_AUTO(winrt::event_token) Revoked(Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> const& handler) const;
        using Revoked_revoker = impl::event_revoker<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession, &impl::abi_t<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>::remove_Revoked>;
        [[nodiscard]] Revoked_revoker Revoked(auto_revoke_t, Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> const& handler) const;
        WINRT_IMPL_AUTO(void) Revoked(winrt::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>) RequestExtensionAsync() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason) Reason() const;
        WINRT_IMPL_AUTO(void) Reason(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason const& value) const;
    };
    template <> struct consume<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ExtendedExecution_Foreground_IExtendedExecutionForegroundSession<D>;
    };
}
#endif

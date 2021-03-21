// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200117.5

#ifndef WINRT_Windows_System_Profile_0_H
#define WINRT_Windows_System_Profile_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename T> struct EventHandler;
    struct EventRegistrationToken;
    template <typename TResult> struct IAsyncOperation;
}
WINRT_EXPORT namespace winrt::Windows::Foundation::Collections
{
    template <typename T> struct IIterable;
    template <typename K, typename V> struct IMapView;
    template <typename T> struct IVectorView;
}
WINRT_EXPORT namespace winrt::Windows::Storage::Streams
{
    struct IBuffer;
}
WINRT_EXPORT namespace winrt::Windows::System
{
    struct User;
}
WINRT_EXPORT namespace winrt::Windows::System::Profile
{
    enum class PlatformDataCollectionLevel : int32_t
    {
        Security = 0,
        Basic = 1,
        Enhanced = 2,
        Full = 3,
    };
    enum class SystemIdentificationSource : int32_t
    {
        None = 0,
        Tpm = 1,
        Uefi = 2,
        Registry = 3,
    };
    enum class SystemOutOfBoxExperienceState : int32_t
    {
        NotStarted = 0,
        InProgress = 1,
        Completed = 2,
    };
    enum class UnsupportedAppRequirementReasons : uint32_t
    {
        Unknown = 0,
        DeniedBySystem = 0x1,
    };
    struct IAnalyticsInfoStatics;
    struct IAnalyticsInfoStatics2;
    struct IAnalyticsVersionInfo;
    struct IAppApplicabilityStatics;
    struct IEducationSettingsStatics;
    struct IHardwareIdentificationStatics;
    struct IHardwareToken;
    struct IKnownRetailInfoPropertiesStatics;
    struct IPlatformDiagnosticsAndUsageDataSettingsStatics;
    struct IRetailInfoStatics;
    struct ISharedModeSettingsStatics;
    struct ISharedModeSettingsStatics2;
    struct ISystemIdentificationInfo;
    struct ISystemIdentificationStatics;
    struct ISystemSetupInfoStatics;
    struct IUnsupportedAppRequirement;
    struct IWindowsIntegrityPolicyStatics;
    struct AnalyticsInfo;
    struct AnalyticsVersionInfo;
    struct AppApplicability;
    struct EducationSettings;
    struct HardwareIdentification;
    struct HardwareToken;
    struct KnownRetailInfoProperties;
    struct PlatformDiagnosticsAndUsageDataSettings;
    struct RetailInfo;
    struct SharedModeSettings;
    struct SystemIdentification;
    struct SystemIdentificationInfo;
    struct SystemSetupInfo;
    struct UnsupportedAppRequirement;
    struct WindowsIntegrityPolicy;
}
namespace winrt::impl
{
    template <> struct category<Windows::System::Profile::IAnalyticsInfoStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IAnalyticsInfoStatics2>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IAnalyticsVersionInfo>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IAppApplicabilityStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IEducationSettingsStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IHardwareIdentificationStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IHardwareToken>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IKnownRetailInfoPropertiesStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IRetailInfoStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::ISharedModeSettingsStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::ISharedModeSettingsStatics2>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::ISystemIdentificationInfo>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::ISystemIdentificationStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::ISystemSetupInfoStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IUnsupportedAppRequirement>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::IWindowsIntegrityPolicyStatics>{ using type = interface_category; };
    template <> struct category<Windows::System::Profile::AnalyticsInfo>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::AnalyticsVersionInfo>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::AppApplicability>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::EducationSettings>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::HardwareIdentification>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::HardwareToken>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::KnownRetailInfoProperties>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::PlatformDiagnosticsAndUsageDataSettings>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::RetailInfo>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::SharedModeSettings>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::SystemIdentification>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::SystemIdentificationInfo>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::SystemSetupInfo>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::UnsupportedAppRequirement>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::WindowsIntegrityPolicy>{ using type = class_category; };
    template <> struct category<Windows::System::Profile::PlatformDataCollectionLevel>{ using type = enum_category; };
    template <> struct category<Windows::System::Profile::SystemIdentificationSource>{ using type = enum_category; };
    template <> struct category<Windows::System::Profile::SystemOutOfBoxExperienceState>{ using type = enum_category; };
    template <> struct category<Windows::System::Profile::UnsupportedAppRequirementReasons>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<Windows::System::Profile::AnalyticsInfo> = L"Windows.System.Profile.AnalyticsInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::AnalyticsVersionInfo> = L"Windows.System.Profile.AnalyticsVersionInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::AppApplicability> = L"Windows.System.Profile.AppApplicability";
    template <> inline constexpr auto& name_v<Windows::System::Profile::EducationSettings> = L"Windows.System.Profile.EducationSettings";
    template <> inline constexpr auto& name_v<Windows::System::Profile::HardwareIdentification> = L"Windows.System.Profile.HardwareIdentification";
    template <> inline constexpr auto& name_v<Windows::System::Profile::HardwareToken> = L"Windows.System.Profile.HardwareToken";
    template <> inline constexpr auto& name_v<Windows::System::Profile::KnownRetailInfoProperties> = L"Windows.System.Profile.KnownRetailInfoProperties";
    template <> inline constexpr auto& name_v<Windows::System::Profile::PlatformDiagnosticsAndUsageDataSettings> = L"Windows.System.Profile.PlatformDiagnosticsAndUsageDataSettings";
    template <> inline constexpr auto& name_v<Windows::System::Profile::RetailInfo> = L"Windows.System.Profile.RetailInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::SharedModeSettings> = L"Windows.System.Profile.SharedModeSettings";
    template <> inline constexpr auto& name_v<Windows::System::Profile::SystemIdentification> = L"Windows.System.Profile.SystemIdentification";
    template <> inline constexpr auto& name_v<Windows::System::Profile::SystemIdentificationInfo> = L"Windows.System.Profile.SystemIdentificationInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::SystemSetupInfo> = L"Windows.System.Profile.SystemSetupInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::UnsupportedAppRequirement> = L"Windows.System.Profile.UnsupportedAppRequirement";
    template <> inline constexpr auto& name_v<Windows::System::Profile::WindowsIntegrityPolicy> = L"Windows.System.Profile.WindowsIntegrityPolicy";
    template <> inline constexpr auto& name_v<Windows::System::Profile::PlatformDataCollectionLevel> = L"Windows.System.Profile.PlatformDataCollectionLevel";
    template <> inline constexpr auto& name_v<Windows::System::Profile::SystemIdentificationSource> = L"Windows.System.Profile.SystemIdentificationSource";
    template <> inline constexpr auto& name_v<Windows::System::Profile::SystemOutOfBoxExperienceState> = L"Windows.System.Profile.SystemOutOfBoxExperienceState";
    template <> inline constexpr auto& name_v<Windows::System::Profile::UnsupportedAppRequirementReasons> = L"Windows.System.Profile.UnsupportedAppRequirementReasons";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IAnalyticsInfoStatics> = L"Windows.System.Profile.IAnalyticsInfoStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IAnalyticsInfoStatics2> = L"Windows.System.Profile.IAnalyticsInfoStatics2";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IAnalyticsVersionInfo> = L"Windows.System.Profile.IAnalyticsVersionInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IAppApplicabilityStatics> = L"Windows.System.Profile.IAppApplicabilityStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IEducationSettingsStatics> = L"Windows.System.Profile.IEducationSettingsStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IHardwareIdentificationStatics> = L"Windows.System.Profile.IHardwareIdentificationStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IHardwareToken> = L"Windows.System.Profile.IHardwareToken";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IKnownRetailInfoPropertiesStatics> = L"Windows.System.Profile.IKnownRetailInfoPropertiesStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics> = L"Windows.System.Profile.IPlatformDiagnosticsAndUsageDataSettingsStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IRetailInfoStatics> = L"Windows.System.Profile.IRetailInfoStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::ISharedModeSettingsStatics> = L"Windows.System.Profile.ISharedModeSettingsStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::ISharedModeSettingsStatics2> = L"Windows.System.Profile.ISharedModeSettingsStatics2";
    template <> inline constexpr auto& name_v<Windows::System::Profile::ISystemIdentificationInfo> = L"Windows.System.Profile.ISystemIdentificationInfo";
    template <> inline constexpr auto& name_v<Windows::System::Profile::ISystemIdentificationStatics> = L"Windows.System.Profile.ISystemIdentificationStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::ISystemSetupInfoStatics> = L"Windows.System.Profile.ISystemSetupInfoStatics";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IUnsupportedAppRequirement> = L"Windows.System.Profile.IUnsupportedAppRequirement";
    template <> inline constexpr auto& name_v<Windows::System::Profile::IWindowsIntegrityPolicyStatics> = L"Windows.System.Profile.IWindowsIntegrityPolicyStatics";
    template <> inline constexpr guid guid_v<Windows::System::Profile::IAnalyticsInfoStatics>{ 0x1D5EE066,0x188D,0x5BA9,{ 0x43,0x87,0xAC,0xAE,0xB0,0xE7,0xE3,0x05 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IAnalyticsInfoStatics2>{ 0x101704EA,0xA7F9,0x46D2,{ 0xAB,0x94,0x01,0x68,0x65,0xAF,0xDB,0x25 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IAnalyticsVersionInfo>{ 0x926130B8,0x9955,0x4C74,{ 0xBD,0xC1,0x7C,0xD0,0xDE,0xCF,0x9B,0x03 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IAppApplicabilityStatics>{ 0x1664A082,0x0F38,0x5C99,{ 0x83,0xE4,0x48,0x99,0x59,0x70,0x86,0x1C } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IEducationSettingsStatics>{ 0xFC53F0EF,0x4D3E,0x4E13,{ 0x9B,0x23,0x50,0x5F,0x4D,0x09,0x1E,0x92 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IHardwareIdentificationStatics>{ 0x971260E0,0xF170,0x4A42,{ 0xBD,0x55,0xA9,0x00,0xB2,0x12,0xDA,0xE2 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IHardwareToken>{ 0x28F6D4C0,0xFB12,0x40A4,{ 0x81,0x67,0x7F,0x4E,0x03,0xD2,0x72,0x4C } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IKnownRetailInfoPropertiesStatics>{ 0x99571178,0x500F,0x487E,{ 0x8E,0x75,0x29,0xE5,0x51,0x72,0x87,0x12 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>{ 0xB6E24C1B,0x7B1C,0x4B32,{ 0x8C,0x62,0xA6,0x65,0x97,0xCE,0x72,0x3A } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IRetailInfoStatics>{ 0x0712C6B8,0x8B92,0x4F2A,{ 0x84,0x99,0x03,0x1F,0x17,0x98,0xD6,0xEF } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::ISharedModeSettingsStatics>{ 0x893DF40E,0xCAD6,0x4D50,{ 0x8C,0x49,0x6F,0xCF,0xC0,0x3E,0xDB,0x29 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::ISharedModeSettingsStatics2>{ 0x608988A4,0xCCF1,0x4EE8,{ 0xA5,0xE2,0xFD,0x6A,0x1D,0x0C,0xFA,0xC8 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::ISystemIdentificationInfo>{ 0x0C659E7D,0xC3C2,0x4D33,{ 0xA2,0xDF,0x21,0xBC,0x41,0x91,0x6E,0xB3 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::ISystemIdentificationStatics>{ 0x5581F42A,0xD3DF,0x4D93,{ 0xA3,0x7D,0xC4,0x1A,0x61,0x6C,0x6D,0x01 } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::ISystemSetupInfoStatics>{ 0x2C9620A8,0x1D88,0x5E2D,{ 0xA3,0x24,0xA5,0x43,0xAF,0x42,0x47,0xEE } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IUnsupportedAppRequirement>{ 0x6182445C,0x894B,0x5CBC,{ 0x89,0x76,0xA9,0x8E,0x0A,0x9B,0x99,0x8D } };
    template <> inline constexpr guid guid_v<Windows::System::Profile::IWindowsIntegrityPolicyStatics>{ 0x7D1D81DB,0x8D63,0x4789,{ 0x9E,0xA5,0xDD,0xCF,0x65,0xA9,0x4F,0x3C } };
    template <> struct default_interface<Windows::System::Profile::AnalyticsVersionInfo>{ using type = Windows::System::Profile::IAnalyticsVersionInfo; };
    template <> struct default_interface<Windows::System::Profile::HardwareToken>{ using type = Windows::System::Profile::IHardwareToken; };
    template <> struct default_interface<Windows::System::Profile::SystemIdentificationInfo>{ using type = Windows::System::Profile::ISystemIdentificationInfo; };
    template <> struct default_interface<Windows::System::Profile::UnsupportedAppRequirement>{ using type = Windows::System::Profile::IUnsupportedAppRequirement; };
    template <> struct abi<Windows::System::Profile::IAnalyticsInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_VersionInfo(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceForm(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IAnalyticsInfoStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetSystemPropertiesAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IAnalyticsVersionInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceFamily(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceFamilyVersion(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IAppApplicabilityStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetUnsupportedAppRequirements(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IEducationSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEducationEnvironment(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IHardwareIdentificationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetPackageSpecificToken(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IHardwareToken>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Signature(void**) noexcept = 0;
            virtual int32_t __stdcall get_Certificate(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IKnownRetailInfoPropertiesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RetailAccessCode(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManufacturerName(void**) noexcept = 0;
            virtual int32_t __stdcall get_ModelName(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayModelName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Price(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsFeatured(void**) noexcept = 0;
            virtual int32_t __stdcall get_FormFactor(void**) noexcept = 0;
            virtual int32_t __stdcall get_ScreenSize(void**) noexcept = 0;
            virtual int32_t __stdcall get_Weight(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_BatteryLifeDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProcessorDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_Memory(void**) noexcept = 0;
            virtual int32_t __stdcall get_StorageDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_GraphicsDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_FrontCameraDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_RearCameraDescription(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasNfc(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasSdSlot(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasOpticalDrive(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsOfficeInstalled(void**) noexcept = 0;
            virtual int32_t __stdcall get_WindowsEdition(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CollectionLevel(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_CollectionLevelChanged(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CollectionLevelChanged(winrt::event_token) noexcept = 0;
            virtual int32_t __stdcall CanCollectDiagnostics(int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IRetailInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsDemoModeEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::ISharedModeSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::ISharedModeSettingsStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ShouldAvoidLocalStorage(bool*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::ISystemIdentificationInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Source(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::ISystemIdentificationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetSystemIdForPublisher(void**) noexcept = 0;
            virtual int32_t __stdcall GetSystemIdForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::ISystemSetupInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OutOfBoxExperienceState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_OutOfBoxExperienceStateChanged(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_OutOfBoxExperienceStateChanged(winrt::event_token) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IUnsupportedAppRequirement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Requirement(void**) noexcept = 0;
            virtual int32_t __stdcall get_Reasons(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::System::Profile::IWindowsIntegrityPolicyStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsEnabledForTrial(bool*) noexcept = 0;
            virtual int32_t __stdcall get_CanDisable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisableSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall add_PolicyChanged(void*, winrt::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PolicyChanged(winrt::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Profile_IAnalyticsInfoStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::System::Profile::AnalyticsVersionInfo) VersionInfo() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DeviceForm() const;
    };
    template <> struct consume<Windows::System::Profile::IAnalyticsInfoStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IAnalyticsInfoStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IAnalyticsInfoStatics2
    {
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, hstring>>) GetSystemPropertiesAsync(param::async_iterable<hstring> const& attributeNames) const;
    };
    template <> struct consume<Windows::System::Profile::IAnalyticsInfoStatics2>
    {
        template <typename D> using type = consume_Windows_System_Profile_IAnalyticsInfoStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IAnalyticsVersionInfo
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DeviceFamily() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DeviceFamilyVersion() const;
    };
    template <> struct consume<Windows::System::Profile::IAnalyticsVersionInfo>
    {
        template <typename D> using type = consume_Windows_System_Profile_IAnalyticsVersionInfo<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IAppApplicabilityStatics
    {
        WINRT_IMPL_AUTO(Windows::Foundation::Collections::IVectorView<Windows::System::Profile::UnsupportedAppRequirement>) GetUnsupportedAppRequirements(param::iterable<hstring> const& capabilities) const;
    };
    template <> struct consume<Windows::System::Profile::IAppApplicabilityStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IAppApplicabilityStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IEducationSettingsStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsEducationEnvironment() const;
    };
    template <> struct consume<Windows::System::Profile::IEducationSettingsStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IEducationSettingsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IHardwareIdentificationStatics
    {
        WINRT_IMPL_AUTO(Windows::System::Profile::HardwareToken) GetPackageSpecificToken(Windows::Storage::Streams::IBuffer const& nonce) const;
    };
    template <> struct consume<Windows::System::Profile::IHardwareIdentificationStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IHardwareIdentificationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IHardwareToken
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) Signature() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) Certificate() const;
    };
    template <> struct consume<Windows::System::Profile::IHardwareToken>
    {
        template <typename D> using type = consume_Windows_System_Profile_IHardwareToken<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IKnownRetailInfoPropertiesStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) RetailAccessCode() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ManufacturerName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ModelName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DisplayModelName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Price() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) IsFeatured() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) FormFactor() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ScreenSize() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Weight() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) DisplayDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) BatteryLifeDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ProcessorDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Memory() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) StorageDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) GraphicsDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) FrontCameraDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) RearCameraDescription() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) HasNfc() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) HasSdSlot() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) HasOpticalDrive() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) IsOfficeInstalled() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) WindowsEdition() const;
    };
    template <> struct consume<Windows::System::Profile::IKnownRetailInfoPropertiesStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IKnownRetailInfoPropertiesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IPlatformDiagnosticsAndUsageDataSettingsStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::System::Profile::PlatformDataCollectionLevel) CollectionLevel() const;
        WINRT_IMPL_AUTO(winrt::event_token) CollectionLevelChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler) const;
        using CollectionLevelChanged_revoker = impl::event_revoker<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics, &impl::abi_t<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>::remove_CollectionLevelChanged>;
        [[nodiscard]] CollectionLevelChanged_revoker CollectionLevelChanged(auto_revoke_t, Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler) const;
        WINRT_IMPL_AUTO(void) CollectionLevelChanged(winrt::event_token const& token) const noexcept;
        WINRT_IMPL_AUTO(bool) CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel const& level) const;
    };
    template <> struct consume<Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IRetailInfoStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsDemoModeEnabled() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>) Properties() const;
    };
    template <> struct consume<Windows::System::Profile::IRetailInfoStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IRetailInfoStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_ISharedModeSettingsStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsEnabled() const;
    };
    template <> struct consume<Windows::System::Profile::ISharedModeSettingsStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_ISharedModeSettingsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_ISharedModeSettingsStatics2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) ShouldAvoidLocalStorage() const;
    };
    template <> struct consume<Windows::System::Profile::ISharedModeSettingsStatics2>
    {
        template <typename D> using type = consume_Windows_System_Profile_ISharedModeSettingsStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_ISystemIdentificationInfo
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Storage::Streams::IBuffer) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::System::Profile::SystemIdentificationSource) Source() const;
    };
    template <> struct consume<Windows::System::Profile::ISystemIdentificationInfo>
    {
        template <typename D> using type = consume_Windows_System_Profile_ISystemIdentificationInfo<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_ISystemIdentificationStatics
    {
        WINRT_IMPL_AUTO(Windows::System::Profile::SystemIdentificationInfo) GetSystemIdForPublisher() const;
        WINRT_IMPL_AUTO(Windows::System::Profile::SystemIdentificationInfo) GetSystemIdForUser(Windows::System::User const& user) const;
    };
    template <> struct consume<Windows::System::Profile::ISystemIdentificationStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_ISystemIdentificationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_ISystemSetupInfoStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::System::Profile::SystemOutOfBoxExperienceState) OutOfBoxExperienceState() const;
        WINRT_IMPL_AUTO(winrt::event_token) OutOfBoxExperienceStateChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler) const;
        using OutOfBoxExperienceStateChanged_revoker = impl::event_revoker<Windows::System::Profile::ISystemSetupInfoStatics, &impl::abi_t<Windows::System::Profile::ISystemSetupInfoStatics>::remove_OutOfBoxExperienceStateChanged>;
        [[nodiscard]] OutOfBoxExperienceStateChanged_revoker OutOfBoxExperienceStateChanged(auto_revoke_t, Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler) const;
        WINRT_IMPL_AUTO(void) OutOfBoxExperienceStateChanged(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::System::Profile::ISystemSetupInfoStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_ISystemSetupInfoStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IUnsupportedAppRequirement
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Requirement() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::System::Profile::UnsupportedAppRequirementReasons) Reasons() const;
    };
    template <> struct consume<Windows::System::Profile::IUnsupportedAppRequirement>
    {
        template <typename D> using type = consume_Windows_System_Profile_IUnsupportedAppRequirement<D>;
    };
    template <typename D>
    struct consume_Windows_System_Profile_IWindowsIntegrityPolicyStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsEnabled() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsEnabledForTrial() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) CanDisable() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsDisableSupported() const;
        WINRT_IMPL_AUTO(winrt::event_token) PolicyChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler) const;
        using PolicyChanged_revoker = impl::event_revoker<Windows::System::Profile::IWindowsIntegrityPolicyStatics, &impl::abi_t<Windows::System::Profile::IWindowsIntegrityPolicyStatics>::remove_PolicyChanged>;
        [[nodiscard]] PolicyChanged_revoker PolicyChanged(auto_revoke_t, Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> const& handler) const;
        WINRT_IMPL_AUTO(void) PolicyChanged(winrt::event_token const& token) const noexcept;
    };
    template <> struct consume<Windows::System::Profile::IWindowsIntegrityPolicyStatics>
    {
        template <typename D> using type = consume_Windows_System_Profile_IWindowsIntegrityPolicyStatics<D>;
    };
}
#endif
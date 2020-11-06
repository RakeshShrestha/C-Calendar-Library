// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200117.5

#ifndef WINRT_Windows_Perception_0_H
#define WINRT_Windows_Perception_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
}
WINRT_EXPORT namespace winrt::Windows::Perception
{
    struct IPerceptionTimestamp;
    struct IPerceptionTimestamp2;
    struct IPerceptionTimestampHelperStatics;
    struct IPerceptionTimestampHelperStatics2;
    struct PerceptionTimestamp;
    struct PerceptionTimestampHelper;
}
namespace winrt::impl
{
    template <> struct category<Windows::Perception::IPerceptionTimestamp>{ using type = interface_category; };
    template <> struct category<Windows::Perception::IPerceptionTimestamp2>{ using type = interface_category; };
    template <> struct category<Windows::Perception::IPerceptionTimestampHelperStatics>{ using type = interface_category; };
    template <> struct category<Windows::Perception::IPerceptionTimestampHelperStatics2>{ using type = interface_category; };
    template <> struct category<Windows::Perception::PerceptionTimestamp>{ using type = class_category; };
    template <> struct category<Windows::Perception::PerceptionTimestampHelper>{ using type = class_category; };
    template <> inline constexpr auto& name_v<Windows::Perception::PerceptionTimestamp> = L"Windows.Perception.PerceptionTimestamp";
    template <> inline constexpr auto& name_v<Windows::Perception::PerceptionTimestampHelper> = L"Windows.Perception.PerceptionTimestampHelper";
    template <> inline constexpr auto& name_v<Windows::Perception::IPerceptionTimestamp> = L"Windows.Perception.IPerceptionTimestamp";
    template <> inline constexpr auto& name_v<Windows::Perception::IPerceptionTimestamp2> = L"Windows.Perception.IPerceptionTimestamp2";
    template <> inline constexpr auto& name_v<Windows::Perception::IPerceptionTimestampHelperStatics> = L"Windows.Perception.IPerceptionTimestampHelperStatics";
    template <> inline constexpr auto& name_v<Windows::Perception::IPerceptionTimestampHelperStatics2> = L"Windows.Perception.IPerceptionTimestampHelperStatics2";
    template <> inline constexpr guid guid_v<Windows::Perception::IPerceptionTimestamp>{ 0x87C24804,0xA22E,0x4ADB,{ 0xBA,0x26,0xD7,0x8E,0xF6,0x39,0xBC,0xF4 } };
    template <> inline constexpr guid guid_v<Windows::Perception::IPerceptionTimestamp2>{ 0xE354B7ED,0x2BD1,0x41B7,{ 0x9E,0xD0,0x74,0xA1,0x5C,0x35,0x45,0x37 } };
    template <> inline constexpr guid guid_v<Windows::Perception::IPerceptionTimestampHelperStatics>{ 0x47A611D4,0xA9DF,0x4EDC,{ 0x85,0x5D,0xF4,0xD3,0x39,0xD9,0x67,0xAC } };
    template <> inline constexpr guid guid_v<Windows::Perception::IPerceptionTimestampHelperStatics2>{ 0x73D1A7FE,0x3FB9,0x4571,{ 0x87,0xD4,0x3C,0x92,0x0A,0x5E,0x86,0xEB } };
    template <> struct default_interface<Windows::Perception::PerceptionTimestamp>{ using type = Windows::Perception::IPerceptionTimestamp; };
    template <> struct abi<Windows::Perception::IPerceptionTimestamp>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TargetTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PredictionAmount(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Perception::IPerceptionTimestamp2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SystemRelativeTargetTime(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Perception::IPerceptionTimestampHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromHistoricalTargetTime(int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Perception::IPerceptionTimestampHelperStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromSystemRelativeTargetTime(int64_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestamp
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::DateTime) TargetTime() const;
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::TimeSpan) PredictionAmount() const;
    };
    template <> struct consume<Windows::Perception::IPerceptionTimestamp>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestamp<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestamp2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(Windows::Foundation::TimeSpan) SystemRelativeTargetTime() const;
    };
    template <> struct consume<Windows::Perception::IPerceptionTimestamp2>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestamp2<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestampHelperStatics
    {
        WINRT_IMPL_AUTO(Windows::Perception::PerceptionTimestamp) FromHistoricalTargetTime(Windows::Foundation::DateTime const& targetTime) const;
    };
    template <> struct consume<Windows::Perception::IPerceptionTimestampHelperStatics>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestampHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Perception_IPerceptionTimestampHelperStatics2
    {
        WINRT_IMPL_AUTO(Windows::Perception::PerceptionTimestamp) FromSystemRelativeTargetTime(Windows::Foundation::TimeSpan const& targetTime) const;
    };
    template <> struct consume<Windows::Perception::IPerceptionTimestampHelperStatics2>
    {
        template <typename D> using type = consume_Windows_Perception_IPerceptionTimestampHelperStatics2<D>;
    };
}
#endif

// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.200117.5

#ifndef WINRT_Windows_Storage_Compression_0_H
#define WINRT_Windows_Storage_Compression_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename TResult> struct IAsyncOperation;
}
WINRT_EXPORT namespace winrt::Windows::Storage::Streams
{
    struct IInputStream;
    struct IOutputStream;
}
WINRT_EXPORT namespace winrt::Windows::Storage::Compression
{
    enum class CompressAlgorithm : int32_t
    {
        InvalidAlgorithm = 0,
        NullAlgorithm = 1,
        Mszip = 2,
        Xpress = 3,
        XpressHuff = 4,
        Lzms = 5,
    };
    struct ICompressor;
    struct ICompressorFactory;
    struct IDecompressor;
    struct IDecompressorFactory;
    struct Compressor;
    struct Decompressor;
}
namespace winrt::impl
{
    template <> struct category<Windows::Storage::Compression::ICompressor>{ using type = interface_category; };
    template <> struct category<Windows::Storage::Compression::ICompressorFactory>{ using type = interface_category; };
    template <> struct category<Windows::Storage::Compression::IDecompressor>{ using type = interface_category; };
    template <> struct category<Windows::Storage::Compression::IDecompressorFactory>{ using type = interface_category; };
    template <> struct category<Windows::Storage::Compression::Compressor>{ using type = class_category; };
    template <> struct category<Windows::Storage::Compression::Decompressor>{ using type = class_category; };
    template <> struct category<Windows::Storage::Compression::CompressAlgorithm>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::Compressor> = L"Windows.Storage.Compression.Compressor";
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::Decompressor> = L"Windows.Storage.Compression.Decompressor";
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::CompressAlgorithm> = L"Windows.Storage.Compression.CompressAlgorithm";
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::ICompressor> = L"Windows.Storage.Compression.ICompressor";
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::ICompressorFactory> = L"Windows.Storage.Compression.ICompressorFactory";
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::IDecompressor> = L"Windows.Storage.Compression.IDecompressor";
    template <> inline constexpr auto& name_v<Windows::Storage::Compression::IDecompressorFactory> = L"Windows.Storage.Compression.IDecompressorFactory";
    template <> inline constexpr guid guid_v<Windows::Storage::Compression::ICompressor>{ 0x0AC3645A,0x57AC,0x4EE1,{ 0xB7,0x02,0x84,0xD3,0x9D,0x54,0x24,0xE0 } };
    template <> inline constexpr guid guid_v<Windows::Storage::Compression::ICompressorFactory>{ 0x5F3D96A4,0x2CFB,0x442C,{ 0xA8,0xBA,0xD7,0xD1,0x1B,0x03,0x9D,0xA0 } };
    template <> inline constexpr guid guid_v<Windows::Storage::Compression::IDecompressor>{ 0xB883FE46,0xD68A,0x4C8B,{ 0xAD,0xA0,0x4E,0xE8,0x13,0xFC,0x52,0x83 } };
    template <> inline constexpr guid guid_v<Windows::Storage::Compression::IDecompressorFactory>{ 0x5337E252,0x1DA2,0x42E1,{ 0x88,0x34,0x03,0x79,0xD2,0x8D,0x74,0x2F } };
    template <> struct default_interface<Windows::Storage::Compression::Compressor>{ using type = Windows::Storage::Compression::ICompressor; };
    template <> struct default_interface<Windows::Storage::Compression::Decompressor>{ using type = Windows::Storage::Compression::IDecompressor; };
    template <> struct abi<Windows::Storage::Compression::ICompressor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FinishAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DetachStream(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Storage::Compression::ICompressorFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateCompressor(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCompressorEx(void*, int32_t, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Storage::Compression::IDecompressor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall DetachStream(void**) noexcept = 0;
        };
    };
    template <> struct abi<Windows::Storage::Compression::IDecompressorFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateDecompressor(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_ICompressor
    {
        WINRT_IMPL_AUTO(Windows::Foundation::IAsyncOperation<bool>) FinishAsync() const;
        WINRT_IMPL_AUTO(Windows::Storage::Streams::IOutputStream) DetachStream() const;
    };
    template <> struct consume<Windows::Storage::Compression::ICompressor>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_ICompressor<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_ICompressorFactory
    {
        WINRT_IMPL_AUTO(Windows::Storage::Compression::Compressor) CreateCompressor(Windows::Storage::Streams::IOutputStream const& underlyingStream) const;
        WINRT_IMPL_AUTO(Windows::Storage::Compression::Compressor) CreateCompressorEx(Windows::Storage::Streams::IOutputStream const& underlyingStream, Windows::Storage::Compression::CompressAlgorithm const& algorithm, uint32_t blockSize) const;
    };
    template <> struct consume<Windows::Storage::Compression::ICompressorFactory>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_ICompressorFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_IDecompressor
    {
        WINRT_IMPL_AUTO(Windows::Storage::Streams::IInputStream) DetachStream() const;
    };
    template <> struct consume<Windows::Storage::Compression::IDecompressor>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_IDecompressor<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_IDecompressorFactory
    {
        WINRT_IMPL_AUTO(Windows::Storage::Compression::Decompressor) CreateDecompressor(Windows::Storage::Streams::IInputStream const& underlyingStream) const;
    };
    template <> struct consume<Windows::Storage::Compression::IDecompressorFactory>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_IDecompressorFactory<D>;
    };
}
#endif

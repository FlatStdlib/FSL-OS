
#include "gfb.h"            // Public
#include "../fsl_efi.h"     // Private

public void init_gfb(fsl_efi *fsl)
{
    EFI_GUID gEfiGraphicsOutputProtocolGuid =
    { 0x9042a9de, 0x23dc, 0x4a38,
      { 0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a } };
    EFI_STATUS Status;
    EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;

    Status = gBS->LocateProtocol(
        &gEfiGraphicsOutputProtocolGuid,
        NULL,
        (VOID **)&Gop
    );

    if(EFI_ERROR(Status)) {
        fsl_panic(L"GOP not found");
        return;
    }

    UINT32 BestMode = 0;
    UINTN MaxPixels = 0;

    for(UINT32 i = 0; i < Gop->Mode->MaxMode; i++) {
        EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *Info;
        UINTN Size;

        if(!EFI_ERROR(Gop->QueryMode(Gop, i, &Size, &Info))) {
            UINTN Pixels = Info->HorizontalResolution * Info->VerticalResolution;
            if (Pixels > MaxPixels) {
                MaxPixels = Pixels;
                BestMode = i;
            }
        }
    }

    Gop->SetMode(Gop, BestMode);

    UINT32 *fb = (UINT32 *)Gop->Mode->FrameBufferBase;
    fsl->framebuffer = fb;
    UINTN pixels = Gop->Mode->FrameBufferSize / 4;

    /* Might not be needed */
    for(UINTN i = 0; i < pixels; i++)
        fb[i] = 0x00000000;

    if(__FSL_DEBUG__)
    {
        print(L"GOP Enabled, Resolution Size: "),
        PrintU32(Gop->Mode->Info->HorizontalResolution), print(L":"),
        PrintU32(Gop->Mode->Info->VerticalResolution), println(NULL);
        print(L"RGB Format: "), PrintU32(Gop->Mode->Info->PixelFormat), println(NULL);
    }

    gST->ConOut->EnableCursor(gST->ConOut, FALSE);
    gST->ConOut->ClearScreen(gST->ConOut);
    fsl->resolution = (screen_size){ 
        .x = Gop->Mode->Info->HorizontalResolution,
        .y = Gop->Mode->Info->VerticalResolution
    }; 
    
    /* Might not be needed */
    UINTN stride = Gop->Mode->Info->PixelsPerScanLine;
    vGop = Gop;
    int base_x = 50;
    int base_y = 50;

    for(int row=0; row<8; row++)
        for(int col=0; col<8; col++)
            _FSLEFI_->framebuffer[(base_y + row) * stride + (base_x + col)] = 0x00FF0000;
}
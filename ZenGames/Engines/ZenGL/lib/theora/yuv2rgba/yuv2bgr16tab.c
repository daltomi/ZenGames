/* YUV-> RGB conversion code.
 *
 * Copyright (C) 2008-9 Robin Watts (robin@wss.co.uk) for Pinknoise
 * Productions Ltd.
 *
 * Licensed under the BSD license. See 'COPYING' for details of
 * (non-)warranty.
 *
 */

/* For BREW or Symbian you might need to make this static const rather than
 * just const, and introduce a function to get the address. */

#include "yuv2rgb.h"

#define REV(X) ((X>>11) & 0x7FF) | ((X & 0x7FF)<<11) | (X & 0xFFE00000)

const uint32_t yuv2bgr565_table[256*3] =
{
	/* y_table */
        REV(0x7FFFFFEDU),
        REV(0x7FFFFFEFU),
        REV(0x7FFFFFF0U),
        REV(0x7FFFFFF1U),
        REV(0x7FFFFFF2U),
        REV(0x7FFFFFF3U),
        REV(0x7FFFFFF4U),
        REV(0x7FFFFFF6U),
        REV(0x7FFFFFF7U),
        REV(0x7FFFFFF8U),
        REV(0x7FFFFFF9U),
        REV(0x7FFFFFFAU),
        REV(0x7FFFFFFBU),
        REV(0x7FFFFFFDU),
        REV(0x7FFFFFFEU),
        REV(0x7FFFFFFFU),
        REV(0x80000000U),
        REV(0x80400801U),
        REV(0x80A01002U),
        REV(0x80E01803U),
        REV(0x81202805U),
        REV(0x81803006U),
        REV(0x81C03807U),
        REV(0x82004008U),
        REV(0x82604809U),
        REV(0x82A0500AU),
        REV(0x82E0600CU),
        REV(0x8340680DU),
        REV(0x8380700EU),
        REV(0x83C0780FU),
        REV(0x84208010U),
        REV(0x84608811U),
        REV(0x84A09813U),
        REV(0x8500A014U),
        REV(0x8540A815U),
        REV(0x8580B016U),
        REV(0x85E0B817U),
        REV(0x8620C018U),
        REV(0x8660D01AU),
        REV(0x86C0D81BU),
        REV(0x8700E01CU),
        REV(0x8740E81DU),
        REV(0x87A0F01EU),
        REV(0x87E0F81FU),
        REV(0x88210821U),
        REV(0x88811022U),
        REV(0x88C11823U),
        REV(0x89012024U),
        REV(0x89412825U),
        REV(0x89A13026U),
        REV(0x89E14028U),
        REV(0x8A214829U),
        REV(0x8A81502AU),
        REV(0x8AC1582BU),
        REV(0x8B01602CU),
        REV(0x8B61682DU),
        REV(0x8BA1782FU),
        REV(0x8BE18030U),
        REV(0x8C418831U),
        REV(0x8C819032U),
        REV(0x8CC19833U),
        REV(0x8D21A034U),
        REV(0x8D61B036U),
        REV(0x8DA1B837U),
        REV(0x8E01C038U),
        REV(0x8E41C839U),
        REV(0x8E81D03AU),
        REV(0x8EE1D83BU),
        REV(0x8F21E83DU),
        REV(0x8F61F03EU),
        REV(0x8FC1F83FU),
        REV(0x90020040U),
        REV(0x90420841U),
        REV(0x90A21042U),
        REV(0x90E22044U),
        REV(0x91222845U),
        REV(0x91823046U),
        REV(0x91C23847U),
        REV(0x92024048U),
        REV(0x92624849U),
        REV(0x92A2504AU),
        REV(0x92E2604CU),
        REV(0x9342684DU),
        REV(0x9382704EU),
        REV(0x93C2784FU),
        REV(0x94228050U),
        REV(0x94628851U),
        REV(0x94A29853U),
        REV(0x9502A054U),
        REV(0x9542A855U),
        REV(0x9582B056U),
        REV(0x95E2B857U),
        REV(0x9622C058U),
        REV(0x9662D05AU),
        REV(0x96C2D85BU),
        REV(0x9702E05CU),
        REV(0x9742E85DU),
        REV(0x97A2F05EU),
        REV(0x97E2F85FU),
        REV(0x98230861U),
        REV(0x98831062U),
        REV(0x98C31863U),
        REV(0x99032064U),
        REV(0x99632865U),
        REV(0x99A33066U),
        REV(0x99E34068U),
        REV(0x9A434869U),
        REV(0x9A83506AU),
        REV(0x9AC3586BU),
        REV(0x9B23606CU),
        REV(0x9B63686DU),
        REV(0x9BA3786FU),
        REV(0x9BE38070U),
        REV(0x9C438871U),
        REV(0x9C839072U),
        REV(0x9CC39873U),
        REV(0x9D23A074U),
        REV(0x9D63B076U),
        REV(0x9DA3B877U),
        REV(0x9E03C078U),
        REV(0x9E43C879U),
        REV(0x9E83D07AU),
        REV(0x9EE3D87BU),
        REV(0x9F23E87DU),
        REV(0x9F63F07EU),
        REV(0x9FC3F87FU),
        REV(0xA0040080U),
        REV(0xA0440881U),
        REV(0xA0A41082U),
        REV(0xA0E42084U),
        REV(0xA1242885U),
        REV(0xA1843086U),
        REV(0xA1C43887U),
        REV(0xA2044088U),
        REV(0xA2644889U),
        REV(0xA2A4588BU),
        REV(0xA2E4608CU),
        REV(0xA344688DU),
        REV(0xA384708EU),
        REV(0xA3C4788FU),
        REV(0xA4248090U),
        REV(0xA4649092U),
        REV(0xA4A49893U),
        REV(0xA504A094U),
        REV(0xA544A895U),
        REV(0xA584B096U),
        REV(0xA5E4B897U),
        REV(0xA624C098U),
        REV(0xA664D09AU),
        REV(0xA6C4D89BU),
        REV(0xA704E09CU),
        REV(0xA744E89DU),
        REV(0xA7A4F09EU),
        REV(0xA7E4F89FU),
        REV(0xA82508A1U),
        REV(0xA88510A2U),
        REV(0xA8C518A3U),
        REV(0xA90520A4U),
        REV(0xA96528A5U),
        REV(0xA9A530A6U),
        REV(0xA9E540A8U),
        REV(0xAA4548A9U),
        REV(0xAA8550AAU),
        REV(0xAAC558ABU),
        REV(0xAB2560ACU),
        REV(0xAB6568ADU),
        REV(0xABA578AFU),
        REV(0xAC0580B0U),
        REV(0xAC4588B1U),
        REV(0xAC8590B2U),
        REV(0xACE598B3U),
        REV(0xAD25A0B4U),
        REV(0xAD65B0B6U),
        REV(0xADA5B8B7U),
        REV(0xAE05C0B8U),
        REV(0xAE45C8B9U),
        REV(0xAE85D0BAU),
        REV(0xAEE5D8BBU),
        REV(0xAF25E8BDU),
        REV(0xAF65F0BEU),
        REV(0xAFC5F8BFU),
        REV(0xB00600C0U),
        REV(0xB04608C1U),
        REV(0xB0A610C2U),
        REV(0xB0E620C4U),
        REV(0xB12628C5U),
        REV(0xB18630C6U),
        REV(0xB1C638C7U),
        REV(0xB20640C8U),
        REV(0xB26648C9U),
        REV(0xB2A658CBU),
        REV(0xB2E660CCU),
        REV(0xB34668CDU),
        REV(0xB38670CEU),
        REV(0xB3C678CFU),
        REV(0xB42680D0U),
        REV(0xB46690D2U),
        REV(0xB4A698D3U),
        REV(0xB506A0D4U),
        REV(0xB546A8D5U),
        REV(0xB586B0D6U),
        REV(0xB5E6B8D7U),
        REV(0xB626C8D9U),
        REV(0xB666D0DAU),
        REV(0xB6C6D8DBU),
        REV(0xB706E0DCU),
        REV(0xB746E8DDU),
        REV(0xB7A6F0DEU),
        REV(0xB7E6F8DFU),
        REV(0xB82708E1U),
        REV(0xB88710E2U),
        REV(0xB8C718E3U),
        REV(0xB90720E4U),
        REV(0xB96728E5U),
        REV(0xB9A730E6U),
        REV(0xB9E740E8U),
        REV(0xBA4748E9U),
        REV(0xBA8750EAU),
        REV(0xBAC758EBU),
        REV(0xBB2760ECU),
        REV(0xBB6768EDU),
        REV(0xBBA778EFU),
        REV(0xBC0780F0U),
        REV(0xBC4788F1U),
        REV(0xBC8790F2U),
        REV(0xBCE798F3U),
        REV(0xBD27A0F4U),
        REV(0xBD67B0F6U),
        REV(0xBDC7B8F7U),
        REV(0xBE07C0F8U),
        REV(0xBE47C8F9U),
        REV(0xBEA7D0FAU),
        REV(0xBEE7D8FBU),
        REV(0xBF27E8FDU),
        REV(0xBF87F0FEU),
        REV(0xBFC7F8FFU),
        REV(0xC0080100U),
        REV(0xC0480901U),
        REV(0xC0A81102U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
        REV(0xC0E82104U),
	/* u_table */
        REV(0x0C400103U),
        REV(0x0C200105U),
        REV(0x0C200107U),
        REV(0x0C000109U),
        REV(0x0BE0010BU),
        REV(0x0BC0010DU),
        REV(0x0BA0010FU),
        REV(0x0BA00111U),
        REV(0x0B800113U),
        REV(0x0B600115U),
        REV(0x0B400117U),
        REV(0x0B400119U),
        REV(0x0B20011BU),
        REV(0x0B00011DU),
        REV(0x0AE0011FU),
        REV(0x0AE00121U),
        REV(0x0AC00123U),
        REV(0x0AA00125U),
        REV(0x0A800127U),
        REV(0x0A600129U),
        REV(0x0A60012BU),
        REV(0x0A40012DU),
        REV(0x0A20012FU),
        REV(0x0A000131U),
        REV(0x0A000132U),
        REV(0x09E00134U),
        REV(0x09C00136U),
        REV(0x09A00138U),
        REV(0x09A0013AU),
        REV(0x0980013CU),
        REV(0x0960013EU),
        REV(0x09400140U),
        REV(0x09400142U),
        REV(0x09200144U),
        REV(0x09000146U),
        REV(0x08E00148U),
        REV(0x08C0014AU),
        REV(0x08C0014CU),
        REV(0x08A0014EU),
        REV(0x08800150U),
        REV(0x08600152U),
        REV(0x08600154U),
        REV(0x08400156U),
        REV(0x08200158U),
        REV(0x0800015AU),
        REV(0x0800015CU),
        REV(0x07E0015EU),
        REV(0x07C00160U),
        REV(0x07A00162U),
        REV(0x07A00164U),
        REV(0x07800166U),
        REV(0x07600168U),
        REV(0x0740016AU),
        REV(0x0720016CU),
        REV(0x0720016EU),
        REV(0x07000170U),
        REV(0x06E00172U),
        REV(0x06C00174U),
        REV(0x06C00176U),
        REV(0x06A00178U),
        REV(0x0680017AU),
        REV(0x0660017CU),
        REV(0x0660017EU),
        REV(0x06400180U),
        REV(0x06200182U),
        REV(0x06000184U),
        REV(0x05E00185U),
        REV(0x05E00187U),
        REV(0x05C00189U),
        REV(0x05A0018BU),
        REV(0x0580018DU),
        REV(0x0580018FU),
        REV(0x05600191U),
        REV(0x05400193U),
        REV(0x05200195U),
        REV(0x05200197U),
        REV(0x05000199U),
        REV(0x04E0019BU),
        REV(0x04C0019DU),
        REV(0x04C0019FU),
        REV(0x04A001A1U),
        REV(0x048001A3U),
        REV(0x046001A5U),
        REV(0x044001A7U),
        REV(0x044001A9U),
        REV(0x042001ABU),
        REV(0x040001ADU),
        REV(0x03E001AFU),
        REV(0x03E001B1U),
        REV(0x03C001B3U),
        REV(0x03A001B5U),
        REV(0x038001B7U),
        REV(0x038001B9U),
        REV(0x036001BBU),
        REV(0x034001BDU),
        REV(0x032001BFU),
        REV(0x032001C1U),
        REV(0x030001C3U),
        REV(0x02E001C5U),
        REV(0x02C001C7U),
        REV(0x02A001C9U),
        REV(0x02A001CBU),
        REV(0x028001CDU),
        REV(0x026001CFU),
        REV(0x024001D1U),
        REV(0x024001D3U),
        REV(0x022001D5U),
        REV(0x020001D7U),
        REV(0x01E001D8U),
        REV(0x01E001DAU),
        REV(0x01C001DCU),
        REV(0x01A001DEU),
        REV(0x018001E0U),
        REV(0x016001E2U),
        REV(0x016001E4U),
        REV(0x014001E6U),
        REV(0x012001E8U),
        REV(0x010001EAU),
        REV(0x010001ECU),
        REV(0x00E001EEU),
        REV(0x00C001F0U),
        REV(0x00A001F2U),
        REV(0x00A001F4U),
        REV(0x008001F6U),
        REV(0x006001F8U),
        REV(0x004001FAU),
        REV(0x004001FCU),
        REV(0x002001FEU),
        REV(0x00000200U),
        REV(0xFFE00202U),
        REV(0xFFC00204U),
        REV(0xFFC00206U),
        REV(0xFFA00208U),
        REV(0xFF80020AU),
        REV(0xFF60020CU),
        REV(0xFF60020EU),
        REV(0xFF400210U),
        REV(0xFF200212U),
        REV(0xFF000214U),
        REV(0xFF000216U),
        REV(0xFEE00218U),
        REV(0xFEC0021AU),
        REV(0xFEA0021CU),
        REV(0xFEA0021EU),
        REV(0xFE800220U),
        REV(0xFE600222U),
        REV(0xFE400224U),
        REV(0xFE200226U),
        REV(0xFE200228U),
        REV(0xFE000229U),
        REV(0xFDE0022BU),
        REV(0xFDC0022DU),
        REV(0xFDC0022FU),
        REV(0xFDA00231U),
        REV(0xFD800233U),
        REV(0xFD600235U),
        REV(0xFD600237U),
        REV(0xFD400239U),
        REV(0xFD20023BU),
        REV(0xFD00023DU),
        REV(0xFCE0023FU),
        REV(0xFCE00241U),
        REV(0xFCC00243U),
        REV(0xFCA00245U),
        REV(0xFC800247U),
        REV(0xFC800249U),
        REV(0xFC60024BU),
        REV(0xFC40024DU),
        REV(0xFC20024FU),
        REV(0xFC200251U),
        REV(0xFC000253U),
        REV(0xFBE00255U),
        REV(0xFBC00257U),
        REV(0xFBC00259U),
        REV(0xFBA0025BU),
        REV(0xFB80025DU),
        REV(0xFB60025FU),
        REV(0xFB400261U),
        REV(0xFB400263U),
        REV(0xFB200265U),
        REV(0xFB000267U),
        REV(0xFAE00269U),
        REV(0xFAE0026BU),
        REV(0xFAC0026DU),
        REV(0xFAA0026FU),
        REV(0xFA800271U),
        REV(0xFA800273U),
        REV(0xFA600275U),
        REV(0xFA400277U),
        REV(0xFA200279U),
        REV(0xFA20027BU),
        REV(0xFA00027CU),
        REV(0xF9E0027EU),
        REV(0xF9C00280U),
        REV(0xF9A00282U),
        REV(0xF9A00284U),
        REV(0xF9800286U),
        REV(0xF9600288U),
        REV(0xF940028AU),
        REV(0xF940028CU),
        REV(0xF920028EU),
        REV(0xF9000290U),
        REV(0xF8E00292U),
        REV(0xF8E00294U),
        REV(0xF8C00296U),
        REV(0xF8A00298U),
        REV(0xF880029AU),
        REV(0xF860029CU),
        REV(0xF860029EU),
        REV(0xF84002A0U),
        REV(0xF82002A2U),
        REV(0xF80002A4U),
        REV(0xF80002A6U),
        REV(0xF7E002A8U),
        REV(0xF7C002AAU),
        REV(0xF7A002ACU),
        REV(0xF7A002AEU),
        REV(0xF78002B0U),
        REV(0xF76002B2U),
        REV(0xF74002B4U),
        REV(0xF74002B6U),
        REV(0xF72002B8U),
        REV(0xF70002BAU),
        REV(0xF6E002BCU),
        REV(0xF6C002BEU),
        REV(0xF6C002C0U),
        REV(0xF6A002C2U),
        REV(0xF68002C4U),
        REV(0xF66002C6U),
        REV(0xF66002C8U),
        REV(0xF64002CAU),
        REV(0xF62002CCU),
        REV(0xF60002CEU),
        REV(0xF60002CFU),
        REV(0xF5E002D1U),
        REV(0xF5C002D3U),
        REV(0xF5A002D5U),
        REV(0xF5A002D7U),
        REV(0xF58002D9U),
        REV(0xF56002DBU),
        REV(0xF54002DDU),
        REV(0xF52002DFU),
        REV(0xF52002E1U),
        REV(0xF50002E3U),
        REV(0xF4E002E5U),
        REV(0xF4C002E7U),
        REV(0xF4C002E9U),
        REV(0xF4A002EBU),
        REV(0xF48002EDU),
        REV(0xF46002EFU),
        REV(0xF46002F1U),
        REV(0xF44002F3U),
        REV(0xF42002F5U),
        REV(0xF40002F7U),
        REV(0xF3E002F9U),
        REV(0xF3E002FBU),
	/* v_table */
        REV(0x1A09A000U),
        REV(0x19E9A800U),
        REV(0x19A9B800U),
        REV(0x1969C800U),
        REV(0x1949D000U),
        REV(0x1909E000U),
        REV(0x18C9E800U),
        REV(0x18A9F800U),
        REV(0x186A0000U),
        REV(0x182A1000U),
        REV(0x180A2000U),
        REV(0x17CA2800U),
        REV(0x17AA3800U),
        REV(0x176A4000U),
        REV(0x172A5000U),
        REV(0x170A6000U),
        REV(0x16CA6800U),
        REV(0x168A7800U),
        REV(0x166A8000U),
        REV(0x162A9000U),
        REV(0x160AA000U),
        REV(0x15CAA800U),
        REV(0x158AB800U),
        REV(0x156AC000U),
        REV(0x152AD000U),
        REV(0x14EAE000U),
        REV(0x14CAE800U),
        REV(0x148AF800U),
        REV(0x146B0000U),
        REV(0x142B1000U),
        REV(0x13EB2000U),
        REV(0x13CB2800U),
        REV(0x138B3800U),
        REV(0x134B4000U),
        REV(0x132B5000U),
        REV(0x12EB6000U),
        REV(0x12CB6800U),
        REV(0x128B7800U),
        REV(0x124B8000U),
        REV(0x122B9000U),
        REV(0x11EBA000U),
        REV(0x11ABA800U),
        REV(0x118BB800U),
        REV(0x114BC000U),
        REV(0x112BD000U),
        REV(0x10EBE000U),
        REV(0x10ABE800U),
        REV(0x108BF800U),
        REV(0x104C0000U),
        REV(0x100C1000U),
        REV(0x0FEC2000U),
        REV(0x0FAC2800U),
        REV(0x0F8C3800U),
        REV(0x0F4C4000U),
        REV(0x0F0C5000U),
        REV(0x0EEC5800U),
        REV(0x0EAC6800U),
        REV(0x0E6C7800U),
        REV(0x0E4C8000U),
        REV(0x0E0C9000U),
        REV(0x0DEC9800U),
        REV(0x0DACA800U),
        REV(0x0D6CB800U),
        REV(0x0D4CC000U),
        REV(0x0D0CD000U),
        REV(0x0CCCD800U),
        REV(0x0CACE800U),
        REV(0x0C6CF800U),
        REV(0x0C4D0000U),
        REV(0x0C0D1000U),
        REV(0x0BCD1800U),
        REV(0x0BAD2800U),
        REV(0x0B6D3800U),
        REV(0x0B2D4000U),
        REV(0x0B0D5000U),
        REV(0x0ACD5800U),
        REV(0x0AAD6800U),
        REV(0x0A6D7800U),
        REV(0x0A2D8000U),
        REV(0x0A0D9000U),
        REV(0x09CD9800U),
        REV(0x098DA800U),
        REV(0x096DB800U),
        REV(0x092DC000U),
        REV(0x090DD000U),
        REV(0x08CDD800U),
        REV(0x088DE800U),
        REV(0x086DF800U),
        REV(0x082E0000U),
        REV(0x07EE1000U),
        REV(0x07CE1800U),
        REV(0x078E2800U),
        REV(0x076E3800U),
        REV(0x072E4000U),
        REV(0x06EE5000U),
        REV(0x06CE5800U),
        REV(0x068E6800U),
        REV(0x064E7800U),
        REV(0x062E8000U),
        REV(0x05EE9000U),
        REV(0x05CE9800U),
        REV(0x058EA800U),
        REV(0x054EB800U),
        REV(0x052EC000U),
        REV(0x04EED000U),
        REV(0x04AED800U),
        REV(0x048EE800U),
        REV(0x044EF000U),
        REV(0x042F0000U),
        REV(0x03EF1000U),
        REV(0x03AF1800U),
        REV(0x038F2800U),
        REV(0x034F3000U),
        REV(0x030F4000U),
        REV(0x02EF5000U),
        REV(0x02AF5800U),
        REV(0x028F6800U),
        REV(0x024F7000U),
        REV(0x020F8000U),
        REV(0x01EF9000U),
        REV(0x01AF9800U),
        REV(0x016FA800U),
        REV(0x014FB000U),
        REV(0x010FC000U),
        REV(0x00EFD000U),
        REV(0x00AFD800U),
        REV(0x006FE800U),
        REV(0x004FF000U),
        REV(0x00100000U),
        REV(0xFFD01000U),
        REV(0xFFB01800U),
        REV(0xFF702800U),
        REV(0xFF303000U),
        REV(0xFF104000U),
        REV(0xFED05000U),
        REV(0xFEB05800U),
        REV(0xFE706800U),
        REV(0xFE307000U),
        REV(0xFE108000U),
        REV(0xFDD09000U),
        REV(0xFD909800U),
        REV(0xFD70A800U),
        REV(0xFD30B000U),
        REV(0xFD10C000U),
        REV(0xFCD0D000U),
        REV(0xFC90D800U),
        REV(0xFC70E800U),
        REV(0xFC30F000U),
        REV(0xFBF10000U),
        REV(0xFBD11000U),
        REV(0xFB911800U),
        REV(0xFB712800U),
        REV(0xFB313000U),
        REV(0xFAF14000U),
        REV(0xFAD14800U),
        REV(0xFA915800U),
        REV(0xFA516800U),
        REV(0xFA317000U),
        REV(0xF9F18000U),
        REV(0xF9D18800U),
        REV(0xF9919800U),
        REV(0xF951A800U),
        REV(0xF931B000U),
        REV(0xF8F1C000U),
        REV(0xF8B1C800U),
        REV(0xF891D800U),
        REV(0xF851E800U),
        REV(0xF831F000U),
        REV(0xF7F20000U),
        REV(0xF7B20800U),
        REV(0xF7921800U),
        REV(0xF7522800U),
        REV(0xF7123000U),
        REV(0xF6F24000U),
        REV(0xF6B24800U),
        REV(0xF6925800U),
        REV(0xF6526800U),
        REV(0xF6127000U),
        REV(0xF5F28000U),
        REV(0xF5B28800U),
        REV(0xF5729800U),
        REV(0xF552A800U),
        REV(0xF512B000U),
        REV(0xF4F2C000U),
        REV(0xF4B2C800U),
        REV(0xF472D800U),
        REV(0xF452E800U),
        REV(0xF412F000U),
        REV(0xF3D30000U),
        REV(0xF3B30800U),
        REV(0xF3731800U),
        REV(0xF3532800U),
        REV(0xF3133000U),
        REV(0xF2D34000U),
        REV(0xF2B34800U),
        REV(0xF2735800U),
        REV(0xF2336800U),
        REV(0xF2137000U),
        REV(0xF1D38000U),
        REV(0xF1B38800U),
        REV(0xF1739800U),
        REV(0xF133A800U),
        REV(0xF113B000U),
        REV(0xF0D3C000U),
        REV(0xF093C800U),
        REV(0xF073D800U),
        REV(0xF033E000U),
        REV(0xF013F000U),
        REV(0xEFD40000U),
        REV(0xEF940800U),
        REV(0xEF741800U),
        REV(0xEF342000U),
        REV(0xEEF43000U),
        REV(0xEED44000U),
        REV(0xEE944800U),
        REV(0xEE745800U),
        REV(0xEE346000U),
        REV(0xEDF47000U),
        REV(0xEDD48000U),
        REV(0xED948800U),
        REV(0xED549800U),
        REV(0xED34A000U),
        REV(0xECF4B000U),
        REV(0xECD4C000U),
        REV(0xEC94C800U),
        REV(0xEC54D800U),
        REV(0xEC34E000U),
        REV(0xEBF4F000U),
        REV(0xEBB50000U),
        REV(0xEB950800U),
        REV(0xEB551800U),
        REV(0xEB352000U),
        REV(0xEAF53000U),
        REV(0xEAB54000U),
        REV(0xEA954800U),
        REV(0xEA555800U),
        REV(0xEA156000U),
        REV(0xE9F57000U),
        REV(0xE9B58000U),
        REV(0xE9958800U),
        REV(0xE9559800U),
        REV(0xE915A000U),
        REV(0xE8F5B000U),
        REV(0xE8B5C000U),
        REV(0xE875C800U),
        REV(0xE855D800U),
        REV(0xE815E000U),
        REV(0xE7F5F000U),
        REV(0xE7B60000U),
        REV(0xE7760800U),
        REV(0xE7561800U),
        REV(0xE7162000U),
        REV(0xE6D63000U),
        REV(0xE6B64000U),
        REV(0xE6764800U),
        REV(0xE6365800U)
};

uint32_t *get_yuv2bgr565_table()
{
  return yuv2bgr565_table;
}

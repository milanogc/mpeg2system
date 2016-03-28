LinkageDescriptor linkage;
NitSection nit;
IntSection intSection;

linkage.setTransportStreamId(?); /* obter do NIT ou do SDT, no SDT os valores possiveis sao 0x42 e 0x46 */
linkage.setOriginalNetworkId(?); /* obter do NIT */
linkage.setServiceId(?); /* obter do SDT */
linkage.setLinkageType(0x0B);
linkage.setPlatformIdDataLength(0);
linkage.appendPlatform(platform); /* update platform_id_data_length */

platform.setPlatformId(?);
platform.setPlatformNameLoopLength(0);
platform.appendPlatformName(platformName); /* updates platform_name_loop_length */

platformName.setIsoLanguageCode(('e' << 16) | ('n' << 8) | 'g');
platformName.setPlatformNameLength(?);
platformName.setText(?);

linkage.finalize();

nit.insertDescriptor(linkage);
nit.finalize();

/* ---------------------------------- */

intSection.setActionType(0x01);
intSection.setPlataformIdHash(?);
intSection.setPlataformId(?);
intSection.setProcessingOrder(0x00); /* ? */

unsigned char ipMacNotificationInfo[] = {
	0x04, /* platform_id_data_length */
	?, /* platform_id 0 */
	?, /* platform_id 1 */
	?, /* platform_id 2 */
	0x01, /* action_type */
	0xC0 /* 1100 0000 reserved 2, INT_version_flag 1, INT_version 5 */
}

unsigned char dataBroadcastIdDescriptor[] = {
	0x66, /* descriptor_tag */
	2 + selector_byte_length, /* descriptor_length */
	0x00, /* data_broadcast_id 0 */
	0x0B, /* data_broadcast_id 1 */
	/* selector bytes... copy ipMacNotificationInfo here */
}

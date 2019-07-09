#if defined _inc_item_map_
	#undef _inc_item_map_
#endif	



stock CreateItemMap(slots, rowblocks)
{	
	new idx;
	if((idx = Iter_Alloc(ItemMap)) > -1)
	{
		memset(itemMapSlot[idx], INVALID_ITEM_DATA, sizeof itemMapSlot[]);
		itemMapBlocksPerRow[idx] = clamp(rowblocks, 1, 6);
		itemMapSize[idx] = clamp(slots, 0, MAX_ITEM_MAP_SLOTS);
		return idx;
	}
	return INVALID;
}


stock DestroyItemMap(index)
{
	if(!Iter_Contains(ItemMap, index))
		return 0;

	memset(itemMapSlot[idx], INVALID_ITEM_DATA, sizeof itemMapSlot[]);
	itemMapBlocksPerRow[index] = 1;
	itemMapSize[mapid] = 0;
	Iter_Remove(ItemMap, index);
	return 1;
}


stock HasSpaceAtItemMap(mapid, slot, itemsx, itemsy)
{
	if(!Iter_Contains(ItemMap, mapid))
		return 0;

	new sumx = slot + (itemsx - 1);
	new sumy = slot + itemMapBlocksPerRow[mapid] * (itemsy - 1);

	if(sumx + (itemMapBlocksPerRow[mapid] * (itemsy - 1)) > (itemMapSize[mapid] - 1))
		return 0;

	for(new a = slot; a <= sumx; a++) {
		for(new b = slot; b <= sumy; b += itemMapBlocksPerRow[mapid]) {
			if(itemMapSlot[mapid][a + b] != INVALID_ITEM_DATA) {
				return 0;
			}
		}
	}
	return 1;
}


stock SetValueInItemMapSlots(mapid, value, start, sizex = 1, sizey = 1)
{
	if(!Iter_Contains(ItemMap, mapid))
		return 0;

	new sumx = start + sizex;
	new sumy = start + itemMapBlocksPerRow[mapid] * (sizey - 1);

	for(new a = start; a < sumx; a++) {
		for(new b = start; b <= sumy; b += itemMapBlocksPerRow[mapid]) {
			itemMapSlot[mapid][a + b] = value;
		}
	}
	return 1;
}





stock DebugMapSlots(mapid)
{
	for(new i; i < itemMapSize[mapid]; i++)
		printf("Mapid: %d | Slot: %d: | Value: %d", mapid, i, itemMapSlot[mapid][i]);
}


/*

TestItemMap()
{
	new mapid = CreateItemMap(13, 5);

	new start = 5;
	new sizex = 3;
	new sizey = 2;

	// SetValueInItemMapSlots(mapid, 555, start, sizex, sizey);

	DebugMapSlots(mapid);

	if(HasSpaceAtItemMap(mapid, start, sizex, sizey)) print("space");
	else print("not space");	
}

*/
#if defined _inc_header_
	#undef _inc_header_
#endif	


//
//	Defines
//


#define MAX_ITEMS 						1000
#define MAX_ITEM_DATA_SLOTS 			2
#define MAX_ITEM_NAME 					14
#define ITEM_IDTF 						1500

#define IsValidItemInList(%0)			(-1 < (%0) < sizeof ItemList)


#define MAX_ITEM_MAPS 					MAX_PLAYERS * 4
#define MAX_ITEM_MAP_SLOTS 				36

#define ALS_DO_ItemRemoveFromWorld<%0>	%0<ItemRemoveFromWorld,d>(end:itemid)
#define ALS_DO_PlayerUseItem<%0>		%0<PlayerUseItem,dd>(more:playerid, end:itemid)
#define ALS_DO_PlayerDropItem<%0>		%0<PlayerDropItem,dd>(more:playerid, end:itemid)

#define MAX_CONTAINERS 					3000
#define MAX_CONTAINER_SLOTS				20


//
//	Variables
//


enum 
{
	ITEM_9MM,
	ITEM_9MM_SD,
	ITEM_DESERT,
	ITEM_SHOTGUN,
	ITEM_SAWN,
	ITEM_SPAS,
	ITEM_UZI,
	ITEM_SMG,
	ITEM_AK47,
	ITEM_M16,
	ITEM_TEC,
	ITEM_RIFLE,
	ITEM_SNIPER,
	ITEM_ORANGE,
	ITEM_TOMATOE,
	ITEM_RED_APPLE,
	ITEM_GREEN_APPLE,
	ITEM_GHILLIE_BAG,
	ITEM_LIGHT_BAG,
	ITEM_MILITARY_BAG,
	ITEM_SMALL_BAG,
	ITEM_SOLDIER_BAG,
	ITEM_FUEL_CAN,
	ITEM_BANDAGE
};


enum e_ITEM_LIST
{
	itmDefName[MAX_ITEM_NAME],
	itmDefModel,
	Float:itmDefRX,
	Float:itmDefRY,
	Float:itmDefOffset,
	bool:itmDefCarry
};

new const ItemList[][e_ITEM_LIST] = 
{
//	name 				model       worldx      worldy      offset      carry
	{"9mm",				346,		93.0,		120.0,		0.000,		false},
	{"9mm SD",			347,		93.0,		120.0,		0.000,		false},
	{"Desert Eagle",	348,		93.0,		120.0,		0.000,		false},
	{"Shotgun",			349,		93.0,		120.0,		0.000,		false},
	{"Spas-12",			350,		93.0,		120.0,		0.000,		false},
	{"Sawn-off",		351,		93.0,		120.0,		0.000,		false},
	{"Micro Uzi",		352,		93.0,		120.0,		0.000,		false},
	{"SMG",				353,		93.0,		120.0,		0.000,		false},
	{"AK-47",			355,		93.0,		120.0,		0.000,		false},
	{"M16",				356,		93.0,		120.0,		0.000,		false},
	{"Tec-9",			372,		93.0,		120.0,		0.000,		false},
	{"Country Rifle",	357,		93.0,		120.0,		0.000,		false},
	{"Sniper Rifle",	358,		93.0,		120.0,		0.000,		false},
	{"Orange",			19574,		0.00,		0.000,		0.000,		false},
	{"Tomatoe",			19577,		0.00,		0.000,		0.000,		false},
	{"Apple",			19576,		0.00,		0.000,		0.151,      false},
	{"Green Apple",		19575,		0.00,		0.000,		0.151,      false},
	{"Ghillie Bag",		-1010,		0.00,		0.000,		0.120,		false},
	{"Light Bag",		-1011,		0.00,		0.000,		0.120,		false},
	{"Military Bag",	-1012,		0.00,		0.000,		0.120,		false},
	{"Small Bag",		-1013,		0.00,		0.000,		0.120,		false},
	{"Soldier Bag",		-1014,		0.00,		0.000,		0.120,		false},
	{"Fuel Can",		1650,		0.00,		0.000,		0.000,		false},
	{"Bandage",		    11747,		0.00,		0.000,		0.000,		false}
};



new const Float:Items_HandPos[][6] = 
{
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// 9mm
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// 9mm SD
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Eagle
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Shotgun
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Sawn
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Spas
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Uzi
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// SMG
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// AK
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// M4
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Tec
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Rifle
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Sniper
	{0.151000,      0.059999,   	0.037999,		0.000000,		0.000000,		0.000000},	// Orange
	{0.151000,      0.059999,   	0.037999,		0.000000,		0.000000,		0.000000},	// Tomatoe
	{0.151000,      0.059999,   	0.037999,		0.000000,		0.000000,		0.000000},	// Apple
	{0.151000,      0.059999,   	0.037999,		0.000000,		0.000000,		0.000000},	// Apple 2
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Ghillie Bag
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Light Bag
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Military bag
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Small bag
	{0.000000,		0.000000,		0.000000,		0.000000,		0.000000,		0.000000},	// Soldier bag
	{0.180100, 		0.038999,   	0.039000,		0.000000,		-98.0999,		0.000000},	// Fuel can
	{0.149000,      0.053000,       0.041000,		0.000000,		0.000000,		0.000000} 	// Bandage					
};


enum e_ITEMS
{
	itmIndex,
	itmObjt,
	itmArea,
	itmWorld,
	itmInterior,
	itmDataInt[MAX_ITEM_DATA_SLOTS],
	Float:itmDataFloat[MAX_ITEM_DATA_SLOTS]
};

new Item[MAX_ITEMS][e_ITEMS];

new Iterator:C_Items<MAX_ITEMS>;
new Iterator:S_Items<MAX_ITEMS>;


const INVALID_ITEM_DATA = (cellmin + 2);
const Float:INVALID_ITEM_DATA_FLOAT = Float:INVALID_ITEM_DATA;
const Float:INVALID_ITEM_POS = Float:cellmin;





new itemMapSlot[MAX_ITEM_MAPS][MAX_ITEM_MAP_SLOTS];
new itemMapBlocksPerRow[MAX_ITEM_MAPS];
new itemMapSize[MAX_ITEM_MAPS];
new Iterator:ItemMap<MAX_ITEM_MAPS>;




new containerSlot[MAX_CONTAINERS][MAX_CONTAINER_SLOTS];
new containerSize[MAX_CONTAINERS];
new containerSlotCount[MAX_CONTAINERS];
new itemContainer[MAX_ITEMS] = {INVALID, ...};
new Iterator:Container<MAX_CONTAINERS>;



new playerHandItem[MAX_PLAYERS] = {INVALID, ...};
new playerUsingItem[MAX_PLAYERS] = {INVALID, ...};
new playerUseItemWheelBarIdx[MAX_PLAYERS] = {INVALID, ...};

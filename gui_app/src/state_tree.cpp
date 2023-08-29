#include "main.h"

#include "lua_interface.h"

extern LuaInterface_Can			LUA_INTERFACE_CAN;
extern LuaInterface_Ktrc_Trc3	LUA_INTERFACE_KTRC_TRC3;
extern LuaInterface_Ktrc_Ars	LUA_INTERFACE_KTRC_ARS;


	StateTreeNode			stateTreeNode_trc3Gen_level = {
			.name = "level",
			.value = &LUA_INTERFACE_KTRC_TRC3.trc3Gen.level,
			.isUnsignedNum = true,
			.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Gen.level)};

	StateTreeNode			stateTreeNode_trc3Gen_carrier = {
			.name = "carrier",
			.value = &LUA_INTERFACE_KTRC_TRC3.trc3Gen.carrier,
			.isUnsignedNum = true,
			.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Gen.carrier)};

	StateTreeNode			stateTreeNode_trc3Gen_mod = {
			.name = "mod",
			.value = &LUA_INTERFACE_KTRC_TRC3.trc3Gen.mod,
			.isUnsignedNum = true,
			.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Gen.mod)};

StateTreeNode			stateTreeNode_trc3Gen = {
		.name = "trc3Gen",
		.value = nullptr,
		.children = {
				&stateTreeNode_trc3Gen_level,
				&stateTreeNode_trc3Gen_carrier,
				&stateTreeNode_trc3Gen_mod
		}};


		StateTreeNode			stateTreeNode_trc3Rec_1_level = {
				.name = "level",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].level,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].level)};

		StateTreeNode			stateTreeNode_trc3Rec_1_carrier = {
				.name = "carrier",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].carrier,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].carrier)};

		StateTreeNode			stateTreeNode_trc3Rec_1_mod = {
				.name = "mod",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].mod,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].mod)};

		StateTreeNode			stateTreeNode_trc3Rec_1_tc = {
				.name = "tc",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].tc,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].tc)};

	StateTreeNode			stateTreeNode_trc3Rec_1 = {
			.name = "[1]",
			.value = nullptr,
			.children = {
					&stateTreeNode_trc3Rec_1_level,
					&stateTreeNode_trc3Rec_1_carrier,
					&stateTreeNode_trc3Rec_1_mod,
					&stateTreeNode_trc3Rec_1_tc
			}};

		StateTreeNode			stateTreeNode_trc3Rec_2_level = {
				.name = "level",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].level,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].level)};

		StateTreeNode			stateTreeNode_trc3Rec_2_carrier = {
				.name = "carrier",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].carrier,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].carrier)};

		StateTreeNode			stateTreeNode_trc3Rec_2_mod = {
				.name = "mod",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].mod,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].mod)};

		StateTreeNode			stateTreeNode_trc3Rec_2_tc = {
				.name = "tc",
				.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].tc,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].tc)};

	StateTreeNode			stateTreeNode_trc3Rec_2 = {
			.name = "[2]",
			.value = nullptr,
			.children = {
					&stateTreeNode_trc3Rec_2_level,
					&stateTreeNode_trc3Rec_2_carrier,
					&stateTreeNode_trc3Rec_2_mod,
					&stateTreeNode_trc3Rec_2_tc
			}};

StateTreeNode			stateTreeNode_trc3Rec = {
		.name = "trc3Rec",
		.value = nullptr,
		.children = {
				&stateTreeNode_trc3Rec_1,
				&stateTreeNode_trc3Rec_2,
		}};



		StateTreeNode			stateTreeNode_arsGen_level_f75 = {
				.name = "f75",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f75,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f75)};

		StateTreeNode			stateTreeNode_arsGen_level_f125 = {
				.name = "f125",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f125,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f125)};

		StateTreeNode			stateTreeNode_arsGen_level_f175 = {
				.name = "f175",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f175,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f175)};

		StateTreeNode			stateTreeNode_arsGen_level_f225 = {
				.name = "f225",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f225,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f225)};

		StateTreeNode			stateTreeNode_arsGen_level_f275 = {
				.name = "f275",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f275,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f275)};

		StateTreeNode			stateTreeNode_arsGen_level_f325 = {
				.name = "f325",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f325,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f325)};

		StateTreeNode			stateTreeNode_arsGen_level_f275_ao = {
				.name = "f275_ao",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.level.f275_ao,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.level.f275_ao)};

	StateTreeNode			stateTreeNode_arsGen_level = {
			.name = "level",
			.value = nullptr,
			.children = {
					&stateTreeNode_arsGen_level_f75,
					&stateTreeNode_arsGen_level_f125,
					&stateTreeNode_arsGen_level_f175,
					&stateTreeNode_arsGen_level_f225,
					&stateTreeNode_arsGen_level_f275,
					&stateTreeNode_arsGen_level_f325,
					&stateTreeNode_arsGen_level_f275_ao
			}};

		StateTreeNode			stateTreeNode_arsGen_gen1_f75 = {
				.name = "f75",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f75,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f75)};

		StateTreeNode			stateTreeNode_arsGen_gen1_f125 = {
				.name = "f125",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f125,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f125)};

		StateTreeNode			stateTreeNode_arsGen_gen1_f175 = {
				.name = "f175",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f175,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f175)};

		StateTreeNode			stateTreeNode_arsGen_gen1_f225 = {
				.name = "f225",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f225,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f225)};

		StateTreeNode			stateTreeNode_arsGen_gen1_f275 = {
				.name = "f275",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f275,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f275)};

		StateTreeNode			stateTreeNode_arsGen_gen1_f325 = {
				.name = "f325",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f325,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f325)};

		StateTreeNode			stateTreeNode_arsGen_gen1_f275_ao = {
				.name = "f275_ao",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f275_ao,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[0].f275_ao)};

	StateTreeNode			stateTreeNode_arsGen_gen1 = {
			.name = "[1]",
			.value = nullptr,
			.children = {
					&stateTreeNode_arsGen_gen1_f75,
					&stateTreeNode_arsGen_gen1_f125,
					&stateTreeNode_arsGen_gen1_f175,
					&stateTreeNode_arsGen_gen1_f225,
					&stateTreeNode_arsGen_gen1_f275,
					&stateTreeNode_arsGen_gen1_f325,
					&stateTreeNode_arsGen_gen1_f275_ao
			}};

		StateTreeNode			stateTreeNode_arsGen_gen2_f75 = {
				.name = "f75",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f75,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f75)};

		StateTreeNode			stateTreeNode_arsGen_gen2_f125 = {
				.name = "f125",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f125,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f125)};

		StateTreeNode			stateTreeNode_arsGen_gen2_f175 = {
				.name = "f175",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f175,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f175)};

		StateTreeNode			stateTreeNode_arsGen_gen2_f225 = {
				.name = "f225",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f225,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f225)};

		StateTreeNode			stateTreeNode_arsGen_gen2_f275 = {
				.name = "f275",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f275,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f275)};

		StateTreeNode			stateTreeNode_arsGen_gen2_f325 = {
				.name = "f325",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f325,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f325)};

		StateTreeNode			stateTreeNode_arsGen_gen2_f275_ao = {
				.name = "f275_ao",
				.value = &LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f275_ao,
				.isUnsignedNum = true,
				.numSize = sizeof(LUA_INTERFACE_KTRC_ARS.arsGen.gen[1].f275_ao)};

	StateTreeNode			stateTreeNode_arsGen_gen2 = {
			.name = "[2]",
			.value = nullptr,
			.children = {
					&stateTreeNode_arsGen_gen2_f75,
					&stateTreeNode_arsGen_gen2_f125,
					&stateTreeNode_arsGen_gen2_f175,
					&stateTreeNode_arsGen_gen2_f225,
					&stateTreeNode_arsGen_gen2_f275,
					&stateTreeNode_arsGen_gen2_f325,
					&stateTreeNode_arsGen_gen2_f275_ao
			}};

StateTreeNode			stateTreeNode_arsGen = {
		.name = "arsGen",
		.value = nullptr,
		.children = {
				&stateTreeNode_arsGen_level,
				&stateTreeNode_arsGen_gen1,
				&stateTreeNode_arsGen_gen2,
		}};


QList<StateTreeNode*>	STATE_TREE_DATA = {
		&stateTreeNode_trc3Gen,
		&stateTreeNode_trc3Rec,
		&stateTreeNode_arsGen
};
#include "main.h"

#include "lua_interface.h"


	StateTreeNode			stateTreeNode_trc3Gen_level = {
			.name = "level",
			.value = &INTERFACE_TRC3_GEN.level,
			.isUnsignedNum = true,
			.numSize = sizeof(INTERFACE_TRC3_GEN.level)};

	StateTreeNode			stateTreeNode_trc3Gen_carrier = {
			.name = "carrier",
			.value = &INTERFACE_TRC3_GEN.carrier,
			.isUnsignedNum = true,
			.numSize = sizeof(INTERFACE_TRC3_GEN.carrier)};

	StateTreeNode			stateTreeNode_trc3Gen_mod = {
			.name = "mod",
			.value = &INTERFACE_TRC3_GEN.mod,
			.isUnsignedNum = true,
			.numSize = sizeof(INTERFACE_TRC3_GEN.mod)};

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
				.value = &INTERFACE_TRC3_REC.rec[0].level,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[0].level)};

		StateTreeNode			stateTreeNode_trc3Rec_1_carrier = {
				.name = "carrier",
				.value = &INTERFACE_TRC3_REC.rec[0].carrier,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[0].carrier)};

		StateTreeNode			stateTreeNode_trc3Rec_1_mod = {
				.name = "mod",
				.value = &INTERFACE_TRC3_REC.rec[0].mod,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[0].mod)};

		StateTreeNode			stateTreeNode_trc3Rec_1_tc = {
				.name = "tc",
				.value = &INTERFACE_TRC3_REC.rec[0].tc,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[0].tc)};

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
				.value = &INTERFACE_TRC3_REC.rec[1].level,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[1].level)};

		StateTreeNode			stateTreeNode_trc3Rec_2_carrier = {
				.name = "carrier",
				.value = &INTERFACE_TRC3_REC.rec[1].carrier,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[1].carrier)};

		StateTreeNode			stateTreeNode_trc3Rec_2_mod = {
				.name = "mod",
				.value = &INTERFACE_TRC3_REC.rec[1].mod,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[1].mod)};

		StateTreeNode			stateTreeNode_trc3Rec_2_tc = {
				.name = "tc",
				.value = &INTERFACE_TRC3_REC.rec[1].tc,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_TRC3_REC.rec[1].tc)};

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
				.value = &INTERFACE_ARS_GEN.level.f75,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.level.f75)};

		StateTreeNode			stateTreeNode_arsGen_level_f125 = {
				.name = "f125",
				.value = &INTERFACE_ARS_GEN.level.f125,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.level.f125)};

		StateTreeNode			stateTreeNode_arsGen_level_f175 = {
				.name = "f175",
				.value = &INTERFACE_ARS_GEN.level.f175,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.level.f175)};

		StateTreeNode			stateTreeNode_arsGen_level_f225 = {
				.name = "f225",
				.value = &INTERFACE_ARS_GEN.level.f225,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.level.f225)};

		StateTreeNode			stateTreeNode_arsGen_level_f275 = {
				.name = "f275",
				.value = &INTERFACE_ARS_GEN.level.f275,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.level.f275)};

		StateTreeNode			stateTreeNode_arsGen_level_f325 = {
				.name = "f325",
				.value = &INTERFACE_ARS_GEN.level.f325,
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.level.f325)};

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
			}};

		StateTreeNode			stateTreeNode_arsGen_gen1_f75 = {
				.name = "f75",
				.value = &INTERFACE_ARS_GEN.gen1[F_075_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_075_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen1_f125 = {
				.name = "f125",
				.value = &INTERFACE_ARS_GEN.gen1[F_125_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_125_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen1_f175 = {
				.name = "f175",
				.value = &INTERFACE_ARS_GEN.gen1[F_175_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_175_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen1_f225 = {
				.name = "f225",
				.value = &INTERFACE_ARS_GEN.gen1[F_225_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_225_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen1_f275 = {
				.name = "f275",
				.value = &INTERFACE_ARS_GEN.gen1[F_275_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_275_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen1_f325 = {
				.name = "f325",
				.value = &INTERFACE_ARS_GEN.gen1[F_325_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_325_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen1_f275_ao = {
				.name = "f275_ao",
				.value = &INTERFACE_ARS_GEN.gen1[F_275_HZ_AO],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen1[F_275_HZ_AO])};

	StateTreeNode			stateTreeNode_arsGen_gen1 = {
			.name = "gen1",
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
				.value = &INTERFACE_ARS_GEN.gen2[F_075_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_075_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen2_f125 = {
				.name = "f125",
				.value = &INTERFACE_ARS_GEN.gen2[F_125_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_125_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen2_f175 = {
				.name = "f175",
				.value = &INTERFACE_ARS_GEN.gen2[F_175_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_175_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen2_f225 = {
				.name = "f225",
				.value = &INTERFACE_ARS_GEN.gen2[F_225_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_225_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen2_f275 = {
				.name = "f275",
				.value = &INTERFACE_ARS_GEN.gen2[F_275_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_275_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen2_f325 = {
				.name = "f325",
				.value = &INTERFACE_ARS_GEN.gen2[F_325_HZ],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_325_HZ])};

		StateTreeNode			stateTreeNode_arsGen_gen2_f275_ao = {
				.name = "f275_ao",
				.value = &INTERFACE_ARS_GEN.gen2[F_275_HZ_AO],
				.isUnsignedNum = true,
				.numSize = sizeof(INTERFACE_ARS_GEN.gen2[F_275_HZ_AO])};

	StateTreeNode			stateTreeNode_arsGen_gen2 = {
			.name = "gen2",
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
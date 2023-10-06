World1_E1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, World1_E1_OnTransition
	.byte 0


World1_E1_OnTransition::
	setflashlevel 4
	end


World1_E1_End::
	lock
	setflag FLAG_CLEARED_W1_E1
	msgbox World1_E1_Text_End
	dynmultipush World1_E1_End_Text_0, 0
	dynmultipush World1_E1_End_Text_1, 1
	dynmultipush World1_E1_End_Text_2, 2
	dynmultistack 0, 0, TRUE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, World1_E1_End_3
	case 1, World1_E1_End_3
	case 2, World1_E1_End_4
World1_E1_End_1:
	releaseall
	end

World1_E1_End_3:
	goto World1_Lobby_Sign_LevelSelection
	goto World1_E1_End_1

World1_E1_End_4:
	warpteleport MAP_POKE_PUZZLE_HUB, 11
	waitstate
	goto World1_E1_End_1


World1_E1_End_Text_0:
	.string "Next Level$"

World1_E1_End_Text_1:
	.string "Select W1 Level$"

World1_E1_End_Text_2:
	.string "Hub$"

World1_E1_Text_End::
	.string "You beat W1-E1!\n"
	.string "Where do you wish to go next?$"

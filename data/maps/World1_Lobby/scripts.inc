World1_Lobby_MapScripts::
	.byte 0


World1_Lobby_Sign_LevelSelection::
	lock
	msgbox World1_Lobby_Text_SelectDifficulty
	dynmultipush World1_Lobby_Text_Easy, 0
	dynmultipush World1_Lobby_Text_Normal, 1
	dynmultipush World1_Lobby_Text_Hard, 2
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, World1_Lobby_Sign_LevelSelection_3
	case 1, World1_Lobby_Sign_LevelSelection_4
	case 2, World1_Lobby_Sign_LevelSelection_5
World1_Lobby_Sign_LevelSelection_1:
	release
	end

World1_Lobby_Sign_LevelSelection_3:
	goto World1_Lobby_Sign_LevelSelection_Easy
	goto World1_Lobby_Sign_LevelSelection_1

World1_Lobby_Sign_LevelSelection_4:
	goto World1_Lobby_Sign_LevelSelection_Normal
	goto World1_Lobby_Sign_LevelSelection_1

World1_Lobby_Sign_LevelSelection_5:
	goto World1_Lobby_Sign_LevelSelection_Hard
	goto World1_Lobby_Sign_LevelSelection_1


World1_Lobby_Sign_LevelSelection_Easy::
	lock
	msgbox World1_Lobby_Text_SelectLevel
	goto_if_set FLAG_CLEARED_W1_E1, World1_Lobby_Sign_LevelSelection_Easy_2
	dynmultipush World1_Lobby_Text_Level1_NotCleared, 0
World1_Lobby_Sign_LevelSelection_Easy_1:
	goto_if_set FLAG_CLEARED_W1_E2, World1_Lobby_Sign_LevelSelection_Easy_6
	dynmultipush World1_Lobby_Text_Level2_NotCleared, 1
World1_Lobby_Sign_LevelSelection_Easy_5:
	goto_if_set FLAG_CLEARED_W1_E3, World1_Lobby_Sign_LevelSelection_Easy_10
	dynmultipush World1_Lobby_Text_Level3_NotCleared, 1
World1_Lobby_Sign_LevelSelection_Easy_9:
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, World1_Lobby_Sign_LevelSelection_Easy_15
	case 1, World1_Lobby_Sign_LevelSelection_Easy_16
	case 2, World1_Lobby_Sign_LevelSelection_Easy_16
World1_Lobby_Sign_LevelSelection_Easy_16:
	goto World1_Lobby_Sign_LevelSelection
World1_Lobby_Sign_LevelSelection_Easy_13:
	releaseall
	end

World1_Lobby_Sign_LevelSelection_Easy_2:
	dynmultipush World1_Lobby_Text_Level1_Cleared, 0
	goto World1_Lobby_Sign_LevelSelection_Easy_1

World1_Lobby_Sign_LevelSelection_Easy_6:
	dynmultipush World1_Lobby_Text_Level2_Cleared, 1
	goto World1_Lobby_Sign_LevelSelection_Easy_5

World1_Lobby_Sign_LevelSelection_Easy_10:
	dynmultipush World1_Lobby_Text_Level3_Cleared, 1
	goto World1_Lobby_Sign_LevelSelection_Easy_9

World1_Lobby_Sign_LevelSelection_Easy_15:
	warpteleport MAP_WORLD1_E1, 0
	waitstate
	goto World1_Lobby_Sign_LevelSelection_Easy_13


World1_Lobby_Sign_LevelSelection_Normal::
	lock
	msgbox World1_Lobby_Text_SelectLevel
	goto_if_set FLAG_CLEARED_W1_N1, World1_Lobby_Sign_LevelSelection_Normal_2
	dynmultipush World1_Lobby_Text_Level1_NotCleared, 0
World1_Lobby_Sign_LevelSelection_Normal_1:
	goto_if_set FLAG_CLEARED_W1_N2, World1_Lobby_Sign_LevelSelection_Normal_6
	dynmultipush World1_Lobby_Text_Level2_NotCleared, 1
World1_Lobby_Sign_LevelSelection_Normal_5:
	goto_if_set FLAG_CLEARED_W1_N3, World1_Lobby_Sign_LevelSelection_Normal_10
	dynmultipush World1_Lobby_Text_Level3_NotCleared, 1
World1_Lobby_Sign_LevelSelection_Normal_9:
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, World1_Lobby_Sign_LevelSelection_Normal_15
	case 1, World1_Lobby_Sign_LevelSelection_Normal_15
	case 2, World1_Lobby_Sign_LevelSelection_Normal_15
World1_Lobby_Sign_LevelSelection_Normal_15:
	goto World1_Lobby_Sign_LevelSelection
	releaseall
	end

World1_Lobby_Sign_LevelSelection_Normal_2:
	dynmultipush World1_Lobby_Text_Level1_Cleared, 0
	goto World1_Lobby_Sign_LevelSelection_Normal_1

World1_Lobby_Sign_LevelSelection_Normal_6:
	dynmultipush World1_Lobby_Text_Level2_Cleared, 1
	goto World1_Lobby_Sign_LevelSelection_Normal_5

World1_Lobby_Sign_LevelSelection_Normal_10:
	dynmultipush World1_Lobby_Text_Level3_Cleared, 1
	goto World1_Lobby_Sign_LevelSelection_Normal_9


World1_Lobby_Sign_LevelSelection_Hard::
	lock
	msgbox World1_Lobby_Text_SelectLevel
	goto_if_set FLAG_CLEARED_W1_H1, World1_Lobby_Sign_LevelSelection_Hard_2
	dynmultipush World1_Lobby_Text_Level1_NotCleared, 0
World1_Lobby_Sign_LevelSelection_Hard_1:
	goto_if_set FLAG_CLEARED_W1_H2, World1_Lobby_Sign_LevelSelection_Hard_6
	dynmultipush World1_Lobby_Text_Level3_NotCleared, 1
World1_Lobby_Sign_LevelSelection_Hard_5:
	goto_if_set FLAG_CLEARED_W1_H3, World1_Lobby_Sign_LevelSelection_Hard_10
	dynmultipush World1_Lobby_Text_Level3_NotCleared, 1
World1_Lobby_Sign_LevelSelection_Hard_9:
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, World1_Lobby_Sign_LevelSelection_Hard_15
	case 1, World1_Lobby_Sign_LevelSelection_Hard_15
	case 2, World1_Lobby_Sign_LevelSelection_Hard_15
World1_Lobby_Sign_LevelSelection_Hard_15:
	goto World1_Lobby_Sign_LevelSelection
	releaseall
	end

World1_Lobby_Sign_LevelSelection_Hard_2:
	dynmultipush World1_Lobby_Text_Level1_Cleared, 0
	goto World1_Lobby_Sign_LevelSelection_Hard_1

World1_Lobby_Sign_LevelSelection_Hard_6:
	dynmultipush World1_Lobby_Text_Level2_Cleared, 1
	goto World1_Lobby_Sign_LevelSelection_Hard_5

World1_Lobby_Sign_LevelSelection_Hard_10:
	dynmultipush World1_Lobby_Text_Level3_Cleared, 1
	goto World1_Lobby_Sign_LevelSelection_Hard_9


World1_Lobby_Text_SelectDifficulty::
	.string "Select a difficulty.$"

World1_Lobby_Text_Easy::
	.string "Easy$"

World1_Lobby_Text_Normal::
	.string "Normal$"

World1_Lobby_Text_Hard::
	.string "Hard$"

World1_Lobby_Text_SelectLevel::
	.string "Select a level to play.$"

World1_Lobby_Text_Level1_Cleared::
	.string "{COLOR GREEN}Level 1$"

World1_Lobby_Text_Level1_NotCleared::
	.string "{COLOR RED}Level 1$"

World1_Lobby_Text_Level2_Cleared::
	.string "{COLOR GREEN}Level 2$"

World1_Lobby_Text_Level2_NotCleared::
	.string "{COLOR RED}Level 2$"

World1_Lobby_Text_Level3_Cleared::
	.string "{COLOR GREEN}Level 3$"

World1_Lobby_Text_Level3_NotCleared::
	.string "{COLOR RED}Level 3$"

PokePuzzleHub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokePuzzleHub_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PokePuzzleHub_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PUZZLE_HUB_STATE, 0, PokePuzzleHub_OnFrame_BirchIntro
	.2byte 0


PokePuzzleHub_OnFrame_BirchIntro::
	lockall
	setvar VAR_PUZZLE_HUB_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, PokePuzzleHub_Movement_Player_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 1, PokePuzzleHub_Movement_Birch_NoticePlayer
	playse SE_PIN
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, PokePuzzleHub_Movement_Player_WalkToBirch
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox PokePuzzleHub_Text_Birch_Greetings
	waitmessage
	closemessage
	applymovement 1, PokePuzzleHub_Movement_Birch_Forgot
	playse SE_PIN
	msgbox PokePuzzleHub_Text_Birch_DeviceOne
	playfanfare MUS_OBTAIN_ITEM
	message PokePuzzleHub_Text_Birch_ObtainedDeviceOne
	waitfanfare
	msgbox PokePuzzleHub_Text_Birch_DeviceTwo
	playfanfare MUS_OBTAIN_ITEM
	message PokePuzzleHub_Text_Birch_ObtainedDeviceTwo
	waitfanfare
	msgbox PokePuzzleHub_Text_Birch_SwingBy
	waitmessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 1
	releaseall
	end


PokePuzzleHub_Movement_Player_FaceUp:
	face_up
	step_end

PokePuzzleHub_Movement_Birch_NoticePlayer:
	face_player
	emote_exclamation_mark
	step_end

PokePuzzleHub_Movement_Player_WalkToBirch:
	walk_up
	step_end

PokePuzzleHub_Movement_Birch_Forgot:
	jump_in_place_down
	emote_exclamation_mark
	step_end

PokePuzzleHub_EventScript_Birch::
	lockall
	faceplayer
	msgbox PokePuzzleHub_Text_Birch_WhatsUp
	dynmultipush PokePuzzleHub_Text_Birch_Devices, 0
	dynmultipush PokePuzzleHub_Text_Birch_Job, 1
	dynmultipush PokePuzzleHub_Text_Birch_Stuck, 2
	dynmultipush PokePuzzleHub_Text_Birch_NeverMind, 3
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, PokePuzzleHub_EventScript_Birch_3
	case 1, PokePuzzleHub_EventScript_Birch_4
	case 2, PokePuzzleHub_EventScript_Birch_5
PokePuzzleHub_EventScript_Birch_1:
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 1
	releaseall
	end

PokePuzzleHub_EventScript_Birch_3:
	msgbox PokePuzzleHub_Text_Birch_ExplainDevices
	waitmessage
	goto PokePuzzleHub_EventScript_Birch_1

PokePuzzleHub_EventScript_Birch_4:
	msgbox PokePuzzleHub_Text_Birch_ExplainJob
	waitmessage
	goto PokePuzzleHub_EventScript_Birch_1

PokePuzzleHub_EventScript_Birch_5:
	msgbox PokePuzzleHub_Text_Birch_ExplainStuck
	waitmessage
	goto PokePuzzleHub_EventScript_Birch_1


PokePuzzleHub_Text_Birch_Greetings::
	.string "BIRCH: Ah, good! You're here!\n"
	.string "So, yeah, this is the Puzzle Lab. Not\l"
	.string "particularly crouded, as you can see.\p"
	.string "But it's a new project after all, so\n"
	.string "there'll be more traffic as we get first\l"
	.string "results.\p"
	.string "We originally divided the types of\n"
	.string "objects for Mew into eight categories\l"
	.string "which now translates to eight types of\l"
	.string "puzzles.\p"
	.string "That's what the numbers above the\n"
	.string "green doors represent.\p"
	.string "You can start with any puzzle you like,\n"
	.string "just enter through the doors and read\l"
	.string "the signs in the room.\p"
	.string "Happy solving!$"

PokePuzzleHub_Text_Birch_DeviceOne::
	.string "BIRCH: Oh, nearly forgot!\p"
	.string "You'll want to have these two devices\n"
	.string "for your work here.\p"
	.string "The first one teleports you right back\n"
	.string "here - to the Puzzle Hub.\p"
	.string "Just press {L_BUTTON} to use it.$"

PokePuzzleHub_Text_Birch_ObtainedDeviceOne::
	.string "{PLAYER} obtained the {COLOR RED}Hub\n"
	.string "Teleporter{COLOR DARK_GRAY}!$"

PokePuzzleHub_Text_Birch_DeviceTwo::
	.string "BIRCH: The second device lets you\n"
	.string "restart the puzzle you are currently\l"
	.string "solving.\p"
	.string "Press {R_BUTTON} to use it.$"

PokePuzzleHub_Text_Birch_ObtainedDeviceTwo::
	.string "{PLAYER} obtained the {COLOR RED}Puzzle\n"
	.string "Restarter{COLOR DARK_GRAY}!$"

PokePuzzleHub_Text_Birch_SwingBy::
	.string "BIRCH: If you have any more questions,\n"
	.string "just swing by. I'll be here in the hub.$"

PokePuzzleHub_Text_Birch_WhatsUp::
	.string "Oh, hey {PLAYER}. What's up?$"

PokePuzzleHub_Text_Birch_Devices::
	.string "Device buttons?$"

PokePuzzleHub_Text_Birch_ExplainDevices::
	.string "The Hub Teleporter teleports you right\n"
	.string "back here - to the Puzzle Hub.\p"
	.string "Just press {L_BUTTON} to use it.\p"
	.string "The Puzzle Restarter lets you restart\n"
	.string "the puzzle you are currently solving.\p"
	.string "Press {R_BUTTON} to use it.$"

PokePuzzleHub_Text_Birch_Job::
	.string "What's my job again?$"

PokePuzzleHub_Text_Birch_ExplainJob::
	.string "Solve puzzles. That simple.$"

PokePuzzleHub_Text_Birch_Stuck::
	.string "The puzzles are too hard for me.$"

PokePuzzleHub_Text_Birch_ExplainStuck::
	.string "You can always take a break if you're\n"
	.string "tired.$"

PokePuzzleHub_Text_Birch_NeverMind::
	.string "Never mind.$"

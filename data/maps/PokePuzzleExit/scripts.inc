PokePuzzleExit_MapScripts::
	.byte 0


PokePuzzleExit_EventScript_Attendant::
	lockall
	faceplayer
	msgbox PokePuzzleExit_Text_Attendant
	release
	end


PokePuzzleExit_EventScript_Scientist::
	lockall
	faceplayer
	msgbox PokePuzzleExit_Text_Scientist
	waitmessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 2
	release
	end


PokePuzzleExit_Text_Attendant::
	.string "Welcome to the Puzzle Lab!\n"
	.string "You can find the Puzzle Hub to your\l"
	.string "right and the building exit to your\l"
	.string "left.$"

PokePuzzleExit_Text_Scientist::
	.string "What? You can't leave the building?\n"
	.string "Hmm. That must be Mew be messing with\l"
	.string "you.\p"
	.string "I'm sure Mew will let you leave at some\n"
	.string "point.\p"
	.string "I suggest you just solve some more\n"
	.string "puzzles for the time being.\p"
	.string "Can't hurt.$"

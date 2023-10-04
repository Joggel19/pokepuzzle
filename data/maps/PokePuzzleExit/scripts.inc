PokePuzzleExit_MapScripts::
	.byte 0


PokePuzzleExit_EventScript_Attendant::
	lockall
	faceplayer
	msgbox PokePuzzleExit_Text_Attendant
	release
	end


PokePuzzleExit_EventScript_Brawly::
	lockall
	faceplayer
	msgbox PokePuzzleExit_Text_Brawly
	waitmessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 2
	release
	end


PokePuzzleExit_Text_Attendant::
	.string "Welcome to the Puzzle Lab!\n"
	.string "You can find the Puzzle Hub to your\l"
	.string "right and the building exit to your\l"
	.string "left.\p"
	.string "Please enjoy your stay!$"

PokePuzzleExit_Text_Brawly::
	.string "BRAWLY: Me? No, I can leave anytime I\n"
	.string "want.\p"
	.string "I just prefer to stay here, absolutely\n"
	.string "voluntary.\p"
	.string "Would be kind of weird if they didn't let\n"
	.string "you leave, right?$"

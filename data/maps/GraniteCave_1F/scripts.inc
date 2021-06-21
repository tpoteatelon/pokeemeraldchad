.set LOCALID_EDDIE, 3

GraniteCave_1F_MapScripts:: @ 822DA5D
	.byte 0

GraniteCave_1F_EventScript_Hiker:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1f_EventScript_EddieInvisible::
	setflag FLAG_EDDIE_BATTLE
	end

GraniteCave_1F_EventScript_EddieRivalBattle::
	lockall
	addobject LOCALID_EDDIE
	setvar VAR_GRANITE_CAVE_1F_STATE, 1
	applymovement 3, Movement_EddieR
	waitmovement 0
	trainerbattle_double TRAINER_EDDIE_R, GraniteCave_1F_Text_EddieRivalIntro, GraniteCave_1F_EddieRivalTextDefeated, GraniteCave_1F_Text_NotEnoughMons, GraniteCave_1F_EventScript_EddieAftermath
	release
	end

 GraniteCave_1F_EventScript_EddieAftermath::
	msgbox GraniteCave_1F_Text_EddieRivalPostBattle
	applymovement 3, Movement_EddieFuckOff
	waitmovement 0
	removeobject LOCALID_EDDIE
	release
	end

GraniteCave_1F_Text_EddieRivalIntro:
	.string "Oh, hey. I was just looking for some new\n"
	.string "Pokemon to fill out my VGC team. While\l"
	.string "you're here, can you test-run it for\l"
	.string "me? Hmm hmm hmm...$"

 GraniteCave_1F_EddieRivalTextDefeated:
	.string "You're not half bad...$"

GraniteCave_1F_Text_NotEnoughMons:
	.string "Sorry, I don't play singles.$"

GraniteCave_1F_Text_EddieRivalPostBattle:
	.string "Wow, you're a strong opponent. I'll have\n"
	.string "to keep an eye on you. I'll see you\l"
	.string "around, buddy!$"

Movement_EddieR:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Movement_EddieFuckOff:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	

GraniteCave_1F_EventScript_ReceivedFlash:: @ 822DA8A
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo: @ 822DA94
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash: @ 822DBB7
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"


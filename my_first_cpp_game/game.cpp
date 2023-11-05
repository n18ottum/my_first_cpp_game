#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_l_p, player_l_dp, player_r_p, player_r_dp;
float puckSpeed = 60.0;
float puck_vpx, puck_vpy, puck_px, puck_py;
bool gameOn = false;
float dirx, diry, randAng;
bool pointScored = true;



internal void simulate_game(Input* input, float dt)
{
	float borderHeight = 50.0;
	float paddleWidth = 2.5;
	float paddleHeight = 12.0;
	clear_screen(0x000000);
	draw_rect(0, 0, 85, borderHeight, 0xffaa33);	//field
	draw_rect(-92.5, 0, 7.5, borderHeight, 0x7f7f7f);	//left goal
	//draw_rect(92.5, 0, 7.5, borderHeight, 0x12af33);	//green goal
	draw_rect(92.5, 0, 7.5, borderHeight, 0x7f7f7f);	//right goal

	//go into game loop when space bar pressed
	if (is_down(BUTTON_SPACE)) gameOn = true;
	
	if (gameOn)
	{
		if (pointScored)
		{
			pointScored = false;
			//generate random numbers for start direction and angle
			randAng = static_cast <float> (rand()/ static_cast <float> (RAND_MAX));
			dirx = ((rand() % 2) * 2) - 1;
			diry = ((rand() % 2) * 2) - 1;
	
		}

		float player_l_ddp = 0.f;
		float player_r_ddp = 0.f;

		if (is_down(BUTTON_Q))	player_l_ddp += 2000;
		if (is_down(BUTTON_A)) player_l_ddp -= 2000;
		if (is_down(BUTTON_9))	player_r_ddp += 2000;
		if (is_down(BUTTON_6)) player_r_ddp -= 2000;

		//friction
		player_l_ddp -= player_l_dp * 10.f;
		player_r_ddp -= player_r_dp * 10.f;

		//Calc puck velocity
		puck_vpx = (puckSpeed * randAng) * dirx;
		puck_vpy = (puckSpeed * (1 - randAng)) * diry;

		//Calc paddle position
		player_l_dp = player_l_dp + (player_l_ddp * dt);
		player_l_p = player_l_p + (player_l_dp * dt) + (player_l_ddp * dt * dt * .5f);
		player_r_dp = player_r_dp + player_r_ddp * dt;
		player_r_p = player_r_p + (player_r_dp * dt) + (player_r_ddp * dt * dt * .5f);

		puck_px = puck_px + (puck_vpx * dt);
		puck_py = puck_py + (puck_vpy * dt);


		if ((player_l_p + paddleHeight) > borderHeight)	player_l_p = (borderHeight)-(paddleHeight);
		if ((player_r_p + paddleHeight) > borderHeight)	player_r_p = (borderHeight)-(paddleHeight);
		if ((player_l_p - paddleHeight) < (0.f - borderHeight))	player_l_p = 0.f - ((borderHeight)-(paddleHeight));
		if ((player_r_p - paddleHeight) < (0.f - borderHeight))	player_r_p = 0.f - ((borderHeight)-(paddleHeight));

		draw_rect(-80, player_l_p, paddleWidth, paddleHeight, 0xff0000);	//left paddle
		draw_rect(80, player_r_p, paddleWidth, paddleHeight, 0xff0000);	//right paddle
		draw_rect(puck_px, puck_py, 1, 1, 0x000000); //puck


	}
	else draw_rect(0, 0, 1, 1, 0x000000); //TODO print out "press space bar to start";

}
#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_l_p, player_l_dp, player_r_p, player_r_dp;

internal void simulate_game(Input* input, float dt)
{
	float borderHeight = 45.0;
	float paddleWidth = 2.5;
	float paddleHeight = 12.0;
	clear_screen(0x000000);
	draw_rect(0, 0, 85, borderHeight, 0xffaa33);	//border

	float player_l_ddp = 0.f;
	float player_r_ddp = 0.f;

	if (is_down(BUTTON_Q))	player_l_ddp += 2000;
	if (is_down(BUTTON_A)) player_l_ddp -= 2000;
	if (is_down(BUTTON_9))	player_r_ddp += 2000;
	if (is_down(BUTTON_6)) player_r_ddp -= 2000;

	player_l_ddp -= player_l_dp * 10.f;
	player_r_ddp -= player_r_dp * 10.f;

	player_l_dp = player_l_dp + player_l_ddp * dt;
	player_l_p = player_l_p + (player_l_dp * dt) + (player_l_ddp * dt * dt * .5f);
	player_r_dp = player_r_dp + player_r_ddp * dt;
	player_r_p = player_r_p + (player_r_dp * dt) + (player_r_ddp * dt * dt * .5f);


	if ((player_l_p + paddleHeight) > borderHeight)	player_l_p = (borderHeight)-(paddleHeight);
	if ((player_r_p + paddleHeight) > borderHeight)	player_r_p = (borderHeight)-(paddleHeight);
	if ((player_l_p - paddleHeight) < (0.f - borderHeight))	player_l_p = 0.f - ((borderHeight)-(paddleHeight));
	if ((player_r_p - paddleHeight) < (0.f - borderHeight))	player_r_p = 0.f -((borderHeight)-(paddleHeight));

	draw_rect(0, 0, 1, 1, 0x000000);	//center square
	draw_rect(-80, player_l_p, paddleWidth, paddleHeight, 0xff0000);	//left paddle
	draw_rect(80, player_r_p, paddleWidth, paddleHeight, 0xff0000);	//right paddle

}
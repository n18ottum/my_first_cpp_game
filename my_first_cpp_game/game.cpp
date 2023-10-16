#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_pos_x = 0.f;
float player_pos_y = 0.f;

internal void simulate_game(Input* input) {
	clear_screen(0xff5500);
	
	if (pressed(BUTTON_UP))	player_pos_y += 1.f;
	if (pressed(BUTTON_DOWN)) player_pos_y -= 1.f;
	if (pressed(BUTTON_RIGHT)) player_pos_x += 1.f;
	if (pressed(BUTTON_LEFT)) player_pos_x -= 1.f;

	draw_rect(player_pos_x, player_pos_y, 1, 1, 0x00ff22);

}
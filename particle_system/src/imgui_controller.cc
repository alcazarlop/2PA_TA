
#include "imgui_controller.h"

void ShowImgui(Entity* entity){

	ImGui::Begin("Demo", nullptr);
	entity = nullptr;

	ImGui::End();

}

void PathWindow(Path* path){

	static Vec2 position = path->position();
	static Vec2 scale = path->scale();
	static float rotation = path->rotation();
	static int color[3] = {0xFF, 0xFF, 0xFF};

	ImGui::Begin("Path Window", nullptr);

	ImGui::Text("Position X"); ImGui::SameLine();
	ImGui::DragFloat("##p1", &position.x);
	ImGui::Text("Position Y"); ImGui::SameLine();
	ImGui::DragFloat("##p1", &position.y);

	ImGui::Text("Scale X"); ImGui::SameLine();
	ImGui::DragFloat("##s1", &scale.x);
	ImGui::Text("Scale Y"); ImGui::SameLine();
	ImGui::DragFloat("##s1", &scale.y);

	ImGui::Text("Rotation"); ImGui::SameLine();
	ImGui::DragFloat("##r1", &rotation);

	ImGui::DragInt("R##r1", &color[0], 1, 0, 255, NULL, ImGuiSliderFlags_AlwaysClamp); 
	ImGui::DragInt("G##g1", &color[1], 1, 0, 255, NULL, ImGuiSliderFlags_AlwaysClamp); 
	ImGui::DragInt("B##b1", &color[2], 1, 0, 255, NULL, ImGuiSliderFlags_AlwaysClamp); 

	path->set_position(position);
	path->set_scale(scale);
	path->set_rotation(rotation);

	// path->set_color((Uint8)color[0], (Uint8)color[1], (Uint8)color[2]);

	ImGui::End();
}

#include "imgui_controller.h"
#include "string"

void ShowImgui(Entity* entity){

	ImGui::Begin("Demo", nullptr);
	entity = nullptr;

	ImGui::End();

}

void PathWindow(Path* path, int tag){

	std::string patata;

	patata = "Particle" + std::to_string(tag);

	if (ImGui::TreeNode(patata.c_str())) {

		Vec2 position = path->position();
		Vec2 scale = path->scale();
		float rotation = path->rotation();
		float* color = path->get_color();

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

		ImGui::Text("Color widget HSV with Alpha:");
		ImGui::ColorEdit3("Color", color, ImGuiColorEditFlags_DisplayHSV);
		/*
		ImGui::DragInt("R##r1", &color[0], 1, 0, 255, NULL, ImGuiSliderFlags_AlwaysClamp);
		ImGui::DragInt("G##g1", &color[1], 1, 0, 255, NULL, ImGuiSliderFlags_AlwaysClamp);
		ImGui::DragInt("B##b1", &color[2], 1, 0, 255, NULL, ImGuiSliderFlags_AlwaysClamp);
		*/
		path->set_position(position);
		path->set_scale(scale);
		path->set_rotation(rotation);

		path->set_color((Uint8)color[0], (Uint8)color[1], (Uint8)color[2]);

		ImGui::TreePop();
	}






}
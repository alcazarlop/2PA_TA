
#include "imgui_controller.h"

void ShowImgui(Entity* entity){

	static Vec3 position = entity->position();
	static Vec3 scale = entity->scale();
	static Vec3 rotation = entity->rotation();

	ImGui::Begin("Demo", nullptr);

	ImGui::DragFloat("Position X", &position.x); 
	// ImGui::SameLine();
	ImGui::DragFloat("Position Y", &position.y); 
	// ImGui::SameLine();
	ImGui::DragFloat("Position Z", &position.z);

	ImGui::DragFloat("Rotation X", &rotation.x, 0.01f); 
	// ImGui::SameLine();
	ImGui::DragFloat("Rotation Y", &rotation.y, 0.01f); 
	// ImGui::SameLine();
	ImGui::DragFloat("Rotation Z", &rotation.z, 0.01f);

	ImGui::DragFloat("Scale X", &scale.x); 
	// ImGui::SameLine();
	ImGui::DragFloat("Scale Y", &scale.y); 
	// ImGui::SameLine();
	ImGui::DragFloat("Scale Z", &scale.z);

	entity->set_position(position);
	entity->set_scale(scale);
	entity->set_rotation(rotation);

	ImGui::End();

}
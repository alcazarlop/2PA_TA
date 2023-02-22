
#include "imgui_controller.h"

void ChangeScene(int* scene){
	ImGui::Begin("Scene Manager");
	if(ImGui::Button("Change Scene")){
		if(*scene == 0) *scene = 1;
		else *scene = 0;
	}
	ImGui::End();
}

void EmitterManager(Emitter* emitter){

	static int emitter_size = 0;

	ImGui::Begin("Emitter Manager");

	ImGui::DragInt("Total particles", &emitter_size);
	if(ImGui::Button("Submit")){
		emitter_size = MathUtils::Clamp(emitter_size, 0, 30);
		emitter->resize(emitter_size);
	}

	ImGui::End();
}


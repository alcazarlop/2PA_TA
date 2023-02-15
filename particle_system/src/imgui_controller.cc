
#include "imgui_controller.h"

void ChangeScene(int* scene){
	ImGui::Begin("Scene Manager");
	if(ImGui::Button("Change Scene")){
		if(*scene == 0) *scene = 1;
		else *scene = 0;
	}
	ImGui::End();
}


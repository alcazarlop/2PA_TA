
#include "imgui_controller.h"

void SceneManager(int* scene, EmitterPool* emitter_pool){
	ImGui::Begin("Scene Manager");

	static int mouseX = 0;
	static int mouseY = 0;

	SDL_GetMouseState(&mouseX, &mouseY);

	if(ImGui::Button("Create Emitter")){
		Emitter* new_emitter = new Emitter();
		new_emitter->init(GameManager::Instance().renderer(), Vec3((float)mouseX, (float)mouseY, 0.0f), 0, 0);		
		emitter_pool->pool_.push_back(new_emitter);
		emitter_pool->isBinded_ = true;
	}

	if(emitter_pool->isBinded_){
		emitter_pool->pool_.back()->sprite()->set_position(Vec3((float)mouseX, (float)mouseY, 0.0f));
	}

	if(ImGui::Button("Change Scene"))
		*scene == 0 ? *scene = 1: *scene = 0;
	
	ImGui::End();
}

void EmitterManager(Emitter* emitter){

	static int emitter_size = emitter->size();
	static int type = (int)emitter->type();
	static int mode = (int)emitter->mode();

	ImGui::Begin("Emitter Manager");

	ImGui::DragInt("Total particles", &emitter_size);

	ImGui::Text("Emitter Type");
	ImGui::RadioButton("Path", &type, 0);
	ImGui::SameLine();
 	ImGui::RadioButton("Sprite", &type, 1);

 	ImGui::Text("Emitter Mode");
	ImGui::RadioButton("Burst", &mode, 0); 
	ImGui::SameLine();
	ImGui::RadioButton("Smoke", &mode, 2);
	ImGui::RadioButton("Firework", &mode, 1);
	ImGui::SameLine();
	ImGui::RadioButton("Waterfall", &mode, 3);

	if(ImGui::Button("Submit")){
		emitter->set_mode((Uint8)mode);
		emitter->set_type((Uint8)type);
		emitter_size = MathUtils::Clamp(emitter_size, 0, Texture::kMaxTexture - 1);
		emitter->resize(emitter_size);
	}

	ImGui::End();
}



#include "imgui_controller.h"

void SceneManager(int* scene, EmitterPool* emitter_pool){
	ImGui::Begin("Scene Manager");

	GameManager& gm = GameManager::Instance();

	if(ImGui::Button("Create Emitter")){
		Emitter* new_emitter = new Emitter();
		new_emitter->init(GameManager::Instance().renderer(), Vec3((float)gm.mouseX(), (float)gm.mouseY(), 0.0f), 0, 0);		
		emitter_pool->pool_.push_back(new_emitter);
		emitter_pool->isBinded_ = true;
	}

	if(emitter_pool->isBinded_){
		emitter_pool->pool_.back()->sprite()->set_position(Vec3((float)gm.mouseX(), (float)gm.mouseY(), 0.0f));
	}

	if(ImGui::Button("Change Scene"))
		*scene == 0 ? *scene = 1: *scene = 0;
	
	ImGui::End();
}

void EmitterManager(Emitter* emitter){

	ImGui::Begin("Emitter Manager");

	ImGui::DragInt("Total particles", &emitter->params_.emitterSize);

	ImGui::Text("Emitter Type");
	ImGui::RadioButton("Path", &emitter->params_.emitterType, 0);
	ImGui::SameLine();
 	ImGui::RadioButton("Sprite", &emitter->params_.emitterType, 1);

 	ImGui::Text("Emitter Mode");
	ImGui::RadioButton("Burst", &emitter->params_.emitterMode, 0); 
	ImGui::SameLine();
	ImGui::RadioButton("Smoke", &emitter->params_.emitterMode, 2);
	ImGui::RadioButton("Firework", &emitter->params_.emitterMode, 1);
	ImGui::SameLine();
	ImGui::RadioButton("Waterfall", &emitter->params_.emitterMode, 3);

	if(ImGui::Button("Submit")){
		emitter->set_mode((Uint8)emitter->params_.emitterMode);
		emitter->set_type((Uint8)emitter->params_.emitterType);
		emitter->params_.emitterSize = MathUtils::Clamp(emitter->params_.emitterSize, 0, Texture::kMaxTexture - 1);
		emitter->resize(emitter->params_.emitterSize);
	}

	ImGui::End();
}


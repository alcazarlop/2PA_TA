
#include "imgui_controller.h"

void SceneManager(int* scene, EmitterPool* emitter_pool, Texture* texture){
	ImGui::Begin("Scene Manager");

	GameManager& gm = GameManager::Instance();

	if(ImGui::Button("Create Emitter")){
		if(Texture::avaliableTextures() >= 1){
			Emitter* new_emitter = new Emitter();
			new_emitter->init();
			new_emitter->set_position(Vec3((float)gm.mouseX(), (float)gm.mouseY(), 0.0f));	
			for(Uint32 i = 0; i < new_emitter->particle_number(); ++i){
				new_emitter->add_particle(texture);
			}	
			emitter_pool->pool_.push_back(new_emitter);
			emitter_pool->isBinded_ = true;
		}
		else {
			ImGui::OpenPopup("Texture");
		}
	}

	if(emitter_pool->isBinded_){
		emitter_pool->pool_.back()->set_position(Vec3((float)gm.mouseX(), (float)gm.mouseY(), 0.0f));
	}

	if(*scene == 0)
		ImGui::Text("Left-click over an emitter to selected it");

	if(ImGui::Button("Change Scene"))
		*scene == 0 ? *scene = 1: *scene = 0;

	if(ImGui::BeginPopup("Texture")){
		ImGui::Text("No more textures avaiable to create an emitter");
		ImGui::EndPopup();
	}
	
	ImGui::End();
}

void EmitterManager(Emitter* emitter, Texture* texture){

	ImGui::Begin("Emitter Manager");

	ImGui::DragInt("Total particles", &emitter->params_.emitterSize);

 	ImGui::Text("Emitter Mode");
	ImGui::RadioButton("Burst", &emitter->params_.emitterMode, 0); 
	ImGui::SameLine();
	ImGui::RadioButton("Smoke", &emitter->params_.emitterMode, 2);
	ImGui::RadioButton("Firework", &emitter->params_.emitterMode, 1);
	ImGui::SameLine();
	ImGui::RadioButton("Waterfall", &emitter->params_.emitterMode, 3);

	if(ImGui::Button("Submit")){
		emitter->set_mode((Uint8)emitter->params_.emitterMode);
		emitter->params_.emitterSize = MathUtils::Clamp(emitter->params_.emitterSize, 0, 128);
		emitter->resize(emitter->params_.emitterSize, texture);
	}

	ImGui::End();
}


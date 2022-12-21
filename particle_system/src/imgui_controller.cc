
#include "imgui_controller.h"

void ChangeScene(int* scene){
	ImGui::Begin("Scene Manager");
	if(ImGui::Button("Change Scene")){
		if(*scene == 0) *scene = 1;
		else *scene = 0;
	}
	ImGui::End();
}

void EmitterPoolManager(EmitterPool* emitter_pool, const WindowController& wc){

	static int mouse_x = 0;
	static int mouse_y = 0;
	static int pool_size = 10;
	static int mode = 0; 
	static int particle_mode = 0;

	SDL_GetMouseState(&mouse_x, &mouse_y); 

	ImGui::Begin("Emitter Pool Manager");
	ImGui::DragInt("Pool size", &pool_size, 1.0f, 1, 128, nullptr, ImGuiSliderFlags_AlwaysClamp);
	ImGui::RadioButton("Firework", &mode, 0); ImGui::SameLine();
	ImGui::RadioButton("Burst", &mode, 1); 

	ImGui::RadioButton("Path", &particle_mode, 0); ImGui::SameLine();
	ImGui::RadioButton("Sprite", &particle_mode, 1); 

	if(ImGui::Button("Create New Emitter")){
		if(emitter_pool->pool_.size() < 32){
			Emitter emitter = Emitter();
			if(emitter_pool->pool_.size() != 0){
				emitter_pool->pool_.back().isBound_ = false;
			}
			emitter_pool->pool_.push_back(emitter);
			emitter_pool->pool_.back().loadSprite(wc.renderer());
			emitter_pool->pool_.back().init(pool_size, mode, particle_mode, wc);
			emitter_pool->pool_.back().isBound_ = true;
		}
	}

	if(emitter_pool->pool_.size() != 0 && emitter_pool->pool_.back().isBound_){
		emitter_pool->pool_.back().set_position((float)mouse_x, (float)mouse_y);
	}

	ImGui::SameLine();
	ImGui::Text("Emitter Count: %d", emitter_pool->pool_.size());

	for(Uint32 i = 0; i < emitter_pool->pool_.size(); ++i){
		EmitterSetup(&emitter_pool->pool_[i], i);
	}

	ImGui::End();
}

void EmitterSetup(Emitter* emitter, int tag){

	std::string id = "Emitter " + std::to_string(tag); 
	static int new_size = 0;
	static int new_mode = 0;

	if(ImGui::TreeNode(id.c_str())){
		ImGui::DragInt("New size", &new_size, 1.0f, 1, 128, nullptr, ImGuiSliderFlags_AlwaysClamp);
		if(ImGui::Button("Set size")){
			emitter->set_pool_size(new_size);
		} 
		ImGui::RadioButton("Firework", &new_mode, 0); ImGui::SameLine();
		ImGui::RadioButton("Burst", &new_mode, 1); ImGui::SameLine(); 
		if(ImGui::RadioButton("Custom", &new_mode, 2)){
			ImGui::OpenPopup("Emitter Params Popup");
		} 

		emitter->set_mode(new_mode);

		EmitterParamsWindow(emitter);
		ImGui::TreePop();
	}

}

void EmitterParamsWindow(Emitter* emitter){

	static bool isVelRandom = true;
	static bool isSpeedRandom = true;
	static bool isLifeTimeRandom = true;
	static bool isLerpColorRandom = true;

	static float min_vel_x = 0.0f;
	static float max_vel_x = 0.0f;
	static float min_vel_y = 0.0f;
	static float max_vel_y = 0.0f;
	static float min_speed = 0.0f;
	static float max_speed = 0.0f;
	static int time = 0;

	static float start_color[3] = {255.0f, 255.0f, 255.0f};
	static float end_color[3] = {255.0f, 255.0f, 255.0f};

	if(ImGui::BeginPopup("Emitter Params Popup")){

		ImGui::Checkbox("Random Velocity", &isVelRandom); ImGui::SameLine();
		// ImGui::Checkbox("Random Lerp Color", &isLerpColorRandom);
		ImGui::Checkbox("Random Speed", &isSpeedRandom); ImGui::SameLine();
		ImGui::Checkbox("Random Lifetime", &isLifeTimeRandom); 

		if(!isVelRandom){
			ImGui::DragFloat("Min Vel X", &min_vel_x, 0.5f, -10.0f, max_vel_x, "%.3f",  ImGuiSliderFlags_AlwaysClamp);
			ImGui::DragFloat("Max Vel X", &max_vel_x, 0.5f, min_vel_x, 10.0f, "%.3f",  ImGuiSliderFlags_AlwaysClamp);
			ImGui::DragFloat("Min Vel Y", &min_vel_y, 0.5f, -10.0f, max_vel_x, "%.3f",  ImGuiSliderFlags_AlwaysClamp);
			ImGui::DragFloat("Max Vel Y", &max_vel_y, 0.5f, min_vel_x, 10.0f, "%.3f", ImGuiSliderFlags_AlwaysClamp);
		}

		// if(!isLerpColorRandom){
		// 	ImGui::ColorEdit3("Start Color", start_color ,ImGuiColorEditFlags_DisplayRGB);
		// 	ImGui::ColorEdit3("End Color", end_color,ImGuiColorEditFlags_DisplayRGB);
		// }

		if(!isSpeedRandom){
			ImGui::DragFloat("Min Speed", &min_speed, 0.2f, 1.0f, max_speed, "%.3f", ImGuiSliderFlags_AlwaysClamp);
			ImGui::DragFloat("Max Speed", &max_speed, 0.2f, min_speed, 5.0f, "%.3f", ImGuiSliderFlags_AlwaysClamp);
		}

		if(!isLifeTimeRandom){
			ImGui::DragInt("Time", &time, 1.0f, 10, 150, nullptr, ImGuiSliderFlags_AlwaysClamp);
		}

		if(ImGui::Button("Submit")){
			if(isVelRandom){
				emitter->set_random_velocity_x();
				emitter->set_random_velocity_y();
			} else {
				emitter->set_particle_velocity_x(min_vel_x, max_vel_x);
				emitter->set_particle_velocity_y(min_vel_y, max_vel_x);
			}

			// if(isLerpColorRandom){
			// 	emitter->set_random_lerpColor();
			// 	emitter->set_random_startColor();
			// 	emitter->set_random_endColor();
			// } else {
			// 	emitter->set_lerpColor(true);
			// 	emitter->set_startColor(Vec4(start_color[0], start_color[1], start_color[2], 255.0f));
			// 	emitter->set_endColor(Vec4(end_color[0], end_color[1], end_color[2], 255.0f));
			// }

			if(isSpeedRandom){
				emitter->set_random_speed();
			} else {
				emitter->set_particle_speed(min_speed, max_speed);
			}

			if(isLifeTimeRandom){
				emitter->set_random_lifetime();
			} else {
				emitter->set_particle_lifetime(time);
			}
	
			ImGui::CloseCurrentPopup();
		}

		if(ImGui::Button("Close")){
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

}

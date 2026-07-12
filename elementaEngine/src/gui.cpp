#include "gui.h"

float Value = 0;

void renderGui(float* XPos, float* YPos, float* XRot, float* XScale, float* YScale) {
	rlImGuiBegin();

	ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;
	ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), dockspace_flags);



	ImGui::Begin("Engine Console");
	ImGui::Text("pos");
	ImGui::DragFloat("xPos", XPos, 1.0f, 0.0f, 0.0f, "%.2f");
	ImGui::DragFloat("yPos", YPos, 1.0f, 0.0f, 0.0f, "%.2f");
	ImGui::Text("rot");
	ImGui::DragFloat("xRot", XRot, 1.0f, 0.0f, 0.0f, "%.2f");
	ImGui::Text("scl");
	ImGui::DragFloat("xScl", XScale, 1.0f, 0.0f, 0.0f, "%.2f");
	ImGui::DragFloat("yScl", YScale, 1.0f, 0.0f, 0.0f, "%.2f");

	ImGui::End();

	rlImGuiEnd();
}

#include <vector>
#include <iostream>

#include "FoodDist_GUI.h"

static void glfw_error_callback(int error, const char* description)
{
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

void FoodDist_GUI::assignFoodDistSystem( std::shared_ptr<FoodDist_DataSource> fdistPtr )
{
  m_foodDistSysPtr = fdistPtr;
}

FoodDist_GUI::FoodDist_GUI()
  : m_clear_color(0.45f, 0.55f, 0.60f, 1.00f), show_demo_window(false), show_schoolList_window(true), m_selectedSchoolIndex(-1),
    m_receivedProduce(false)
{
  // Setup window
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) {
    std::cerr << "Unable to initialize GLFW!" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
  // GL ES 2.0 + GLSL 100
  const char* glsl_version = "#version 100";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
  // GL 3.2 + GLSL 150
  const char* glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
  // GL 3.0 + GLSL 130
  const char* glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

  // Create window with graphics context
  m_window = glfwCreateWindow(1280, 720, m_windowTitle.data(), NULL, NULL);
  assert( m_window );

  glfwMakeContextCurrent(m_window);
  glfwSwapInterval(1); // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  //ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(m_window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  // Load Fonts
  // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
  // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
  // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
  // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
  // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
  // - Read 'docs/FONTS.md' for more instructions and details.
  // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
  //io.Fonts->AddFontDefault();
  //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
  //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
  //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
  //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
  //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
  //IM_ASSERT(font != NULL);
}

FoodDist_GUI::~FoodDist_GUI()
{
  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void FoodDist_GUI::mainLoop()
{
  while (!glfwWindowShouldClose(m_window))
    {
      // Poll and handle events (inputs, window resize, etc.)
      // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
      // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
      // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
      // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
      glfwPollEvents();

      // Start the Dear ImGui frame
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      // Want to see what imGUI is capable of?  Set show_demo_window to true (in the constructor) and you'll get all the options.
      // 
      // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
      if (show_demo_window)
	ImGui::ShowDemoWindow(&show_demo_window);

      const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
      // Window that has a button to request the next produce type.
      {
	static std::string prType;
	static float prWeight;
	static float prCost;
	static std::string prFarm;

	ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);
	ImGui::Begin("Produce Window");                         // Create a window called "Produce Window" and append into it.

	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	
	// Buttons return true when clicked (most widgets return true when edited/activated)
	if (ImGui::Button("Retrieve Highest Priority Produce")) {
	  m_receivedProduce = m_foodDistSysPtr->retrieveHightestPriorityProduce( prType, prWeight, prCost, prFarm );
	}
	
	ImGui::Dummy(ImVec2(0.0f, 20.0f));

	if (m_receivedProduce) {
	  ImGui::Text("Next Produce Available!");
	  ImGui::Text("Type: %s", prType.c_str());
	  ImGui::Text("Weight: %.2f", prWeight);
	  ImGui::Text("Cost: %.2f", prCost);
	  ImGui::Text("Farm: %s", prFarm.c_str());
	  ImGui::Spacing();
	  ImGui::Text("Total Cost: %.2f", prWeight * prCost);
	}
	else {
	  ImGui::Text("Produce not available or all produce is distributed.");
	  ImGui::Text("Try pressing the retrieve produce button above.");
	  ImGui::Text("If you keep getting this message, after pressing the");
	  ImGui::Text("button, no more produce is available.");
	}

	ImGui::Dummy(ImVec2(0.0f, 20.0f));
	
	if (m_receivedProduce) {
	  if (ImGui::Button("Purchase Produce for Selected School")) {
	    
	    // Purchase Produce!
	    if (m_selectedSchoolIndex == -1) {

	      std::cerr << "No school selected!" << std::endl;
	      ImGui::OpenPopup("popupError_noselection");
	      if (ImGui::BeginPopup("popupError_noselection", ImGuiWindowFlags_MenuBar)) {
		ImGui::Separator();
		ImGui::Text("No School Selected");
		ImGui::Separator();
		ImGui::EndPopup();
	      }

	    }
	    else if ((m_selectedSchoolBudget - (prWeight * prCost)) < 0) {
	      
	      std::cerr << "Not enought money!" << std::endl;
	      ImGui::OpenPopup("not_enough_money");
	      if (ImGui::BeginPopup("not_enough_money")) {
		ImGui::Separator();
		ImGui::Text("Not enough money in budget!");
		ImGui::Separator();
		ImGui::EndPopup();
	      }

	    }
	    else {
	      ImGui::Text("Purchasing %s for %s", prType.c_str(), m_selectedSchoolName.c_str());
	      m_selectedSchoolBudget = m_selectedSchoolBudget - (prWeight * prCost);
	      m_foodDistSysPtr->changeSchoolBudget( m_selectedSchoolIndex, m_selectedSchoolBudget );

	      // now that it's been purchased, need to get more produce
	      m_receivedProduce = false;
	    }
	  }
	}

	ImGui::Dummy(ImVec2(0.0f, 10.0f));
	
	if (m_receivedProduce) {
	  if (ImGui::Button("Return Produce")) {
	    m_foodDistSysPtr->returnMostRecentProduceAndLowerPriority();
	    m_receivedProduce = false;
	  }
	}


	// ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
      }

      // 3. Show another simple window.
      if (show_schoolList_window)
        {
	  ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
	  ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 20, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);
	  ImGui::Begin("Participating Schools Window", &show_schoolList_window);
	  ImGui::Text("List of participating schools.");

	  // extract data from FoodDist_Data and place into table

	  static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
	  const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();

	  static std::string sSchoolName;
	  static float sSchoolBudget;

	  // Show up to eight rows
	  // w/ three columns
	  ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 8);
	  if (ImGui::BeginTable("table_schools", 3, flags, outer_size))
	    {
	      ImGui::TableSetupScrollFreeze(0, 1); // Make top row always visible
	      ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_None);
	      ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_None);
	      ImGui::TableSetupColumn("Budget", ImGuiTableColumnFlags_None);
	      ImGui::TableHeadersRow();

	      // Demonstrate using clipper for large vertical lists
	      // This is here in case the list of schools ever becomes too
	      // large.  This will allow it to be scrollable.
	      auto numSchools = m_foodDistSysPtr->retrieveNumberSchools();

	      ImGuiListClipper clipper;
	      if (numSchools > 8)
		clipper.Begin(8);
	      else
		clipper.Begin( numSchools );
	      
	      bool selected = false;
	      while (clipper.Step())
		{
		  // For all of the 
		  for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++)
		    {
		      ImGui::TableNextRow();
			
		      ImGui::TableSetColumnIndex(0);

		      auto schName = m_foodDistSysPtr->retrieveSchoolName( row );
		      auto schType = m_foodDistSysPtr->retrieveSchoolType( row );
		      auto schBudget = m_foodDistSysPtr->retrieveSchoolBudget( row );
		      
		      if (ImGui::Selectable(schName.c_str(), &selected, ImGuiSelectableFlags_SpanAllColumns)) {
			m_selectedSchoolIndex = row;
			m_selectedSchoolName = schName;
			m_selectedSchoolBudget = schBudget;
		      }
		      else {
			selected = false;
		      }

		      ImGui::TableSetColumnIndex(1);
		      ImGui::Text("%s", schType.c_str());
			
		      ImGui::TableSetColumnIndex(2);
		      ImGui::Text("%0.2f", schBudget);

		    }
		}
	      ImGui::EndTable();
	    }

	  ImGui::Dummy(ImVec2(0.0f, 40.0f));
	  ImGui::Text("Selected the following school to purchase the next produce:");
	  ImGui::Spacing();
	  ImGui::Text("School: %s", m_selectedSchoolName.c_str());
	  ImGui::Text("Budget: %0.2f", m_selectedSchoolBudget);
	    
	  ImGui::End();
        }

      // Rendering
      ImGui::Render();
      int display_w, display_h;
      glfwGetFramebufferSize(m_window, &display_w, &display_h);
      glViewport(0, 0, display_w, display_h);
      glClearColor(m_clear_color.x * m_clear_color.w, m_clear_color.y * m_clear_color.w, m_clear_color.z * m_clear_color.w, m_clear_color.w);
      glClear(GL_COLOR_BUFFER_BIT);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

      glfwSwapBuffers(m_window);
    }
}

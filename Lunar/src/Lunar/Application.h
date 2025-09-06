// The error "expected a declaration" is likely caused by a missing semicolon after the class declaration.
// Ensure the closing brace of the class is followed by a semicolon.

#pragma once
#include "Core.h"

namespace Lunar {
	class LUNAR_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}
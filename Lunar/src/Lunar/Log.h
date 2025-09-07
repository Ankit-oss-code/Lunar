#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lunar
{
	class LUNAR_API Log
	{
	public:
		void static Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		private:
		#pragma warning(push)
		#pragma warning(disable: 4251)
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		#pragma warning(pop)
	};

}


#define LU_CORE_ERROR(...)    ::Lunar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LU_CORE_WARN(...)     ::Lunar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LU_CORE_INFO(...)     ::Lunar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LU_CORE_TRACE(...)    ::Lunar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LU_CORE_FATAL(...)    ::Lunar::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define LU_ERROR(...)         ::Lunar::Log::GetClientLogger()->error(__VA_ARGS__)
#define LU_WARN(...)          ::Lunar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LU_INFO(...)          ::Lunar::Log::GetClientLogger()->info(__VA_ARGS__)
#define LU_TRACE(...)         ::Lunar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LU_FATAL(...)         ::Lunar::Log::GetClientLogger()->fatal(__VA_ARGS__)





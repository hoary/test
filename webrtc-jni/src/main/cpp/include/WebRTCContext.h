/*
 * Copyright 2019 Alex Andres
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef JNI_WEBRTC_CONTEXT_H_
#define JNI_WEBRTC_CONTEXT_H_

#include "JavaContext.h"
#include "media/audio/AudioDeviceManager.h"
#include "media/video/VideoDeviceManager.h"

#include <jni.h>
#include <memory>
#include <mutex>

namespace jni
{
	class WebRTCContext : public JavaContext
	{
		public:
			WebRTCContext(JavaVM * vm);
			~WebRTCContext() = default;

			void initialize(JNIEnv * env) override;
			void initializeClassLoader(JNIEnv* env, const char * loaderName) override;
			void destroy(JNIEnv * env) override;

			avdev::AudioDeviceManager * getAudioDeviceManager();
			avdev::VideoDeviceManager * getVideoDeviceManager();

		private:
			void initializeAudioManager();
			void initializeVideoManager();

		private:
			std::mutex aMutex;
			std::mutex vMutex;
			std::unique_ptr<avdev::AudioDeviceManager> audioDevManager;
			std::unique_ptr<avdev::VideoDeviceManager> videoDevManager;
	};
}

#endif
 

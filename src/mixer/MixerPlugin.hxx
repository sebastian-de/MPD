/*
 * Copyright (C) 2003-2014 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/** \file
 *
 * This header declares the mixer_plugin class.  It should not be
 * included directly; use MixerInternal.hxx instead in mixer
 * implementations.
 */

#ifndef MPD_MIXER_PLUGIN_HXX
#define MPD_MIXER_PLUGIN_HXX

struct config_param;
struct AudioOutput;
class Mixer;
class EventLoop;
class Error;

struct MixerPlugin {
	/**
         * Alocates and configures a mixer device.
	 *
	 * @param ao the associated AudioOutput
	 * @param param the configuration section
	 * @param error_r location to store the error occurring, or
	 * nullptr to ignore errors
	 * @return a mixer object, or nullptr on error
	 */
	Mixer *(*init)(EventLoop &event_loop, AudioOutput &ao,
		       const config_param &param,
		       Error &error);

	/**
	 * If true, then the mixer is automatically opened, even if
	 * its audio output is not open.  If false, then the mixer is
	 * disabled as long as its audio output is closed.
	 */
	bool global;
};

#endif

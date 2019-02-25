//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef MUD_MODULES
module toy.core
#else
#include <ecs/ECS.hpp>
#include <core/Types.h>
#include <core/World/Origin.h>
#endif

namespace toy
{
	Entity Origin::create(ECS& ecs, World& world)
	{
		Entity entity = { ecs.create<Spatial, Origin>(), ecs.m_index };
		ecs.set(entity, Spatial(world, HSpatial(), vec3(0.f), ZeroQuat));
		ecs.set(entity, Origin(entity));
		return entity;
	}

	Origin::Origin(HSpatial spatial)
		: m_spatial(spatial)
	{}
}

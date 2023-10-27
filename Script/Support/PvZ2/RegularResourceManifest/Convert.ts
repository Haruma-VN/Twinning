namespace TwinStar.Script.Support.PvZ2.RegularResourceManifest.Convert {

	// ------------------------------------------------

	export function from_official(
		source: ResourceManifest.Package,
	): RegularResourceManifest.Package {
		let destination: RegularResourceManifest.Package = {
			group: {},
		};
		for (let source_group of source.groups) {
			assert_test(ResourceManifest.GroupTypeE.includes(source_group.type), `group type invalid`);
			switch (source_group.type) {
				case 'composite': {
					destination.group[source_group.id] = {
						composite: true,
						subgroup: {},
					};
					break;
				}
				case 'simple': {
					let source_subgroup = source_group as ResourceManifest.SimpleGroupAdditional;
					let destination_group: RegularResourceManifest.Group;
					if (source_subgroup.parent === undefined) {
						destination.group[source_group.id] = {
							composite: false,
							subgroup: {},
						};
						destination_group = destination.group[source_group.id];
					} else {
						let destination_group_if = destination.group[source_subgroup.parent];
						assert_test(destination_group_if !== undefined, `subgroup's parent is not found : ${source_group.id}`);
						destination_group = destination_group_if;
					}
					destination_group.subgroup[source_group.id] = {
						category: [
							not_equal_or(JSONGenericGetter.integer(source_subgroup.res, 0n), 0n, null),
							not_equal_or(JSONGenericGetter.string(source_subgroup.loc, ''), '', null),
						],
						resource: {},
					};
					let destination_subgroup = destination_group.subgroup[source_group.id];
					for (let source_resource of source_subgroup.resources) {
						let destination_resource_path = typeof source_resource.path === 'string' ? PathUtility.regularize(source_resource.path) : PathUtility.catenate(source_resource.path);
						if ('atlas' in source_resource) {
							destination_subgroup.resource[source_resource.id] = {
								path: destination_resource_path,
								type: source_resource.type,
								additional: {
									type: 'atlas',
									value: {
										size: [
											JSONGenericGetter.integer(source_resource.width),
											JSONGenericGetter.integer(source_resource.height),
										],
										sprite: {},
									},
								},
							};
						} else if ('parent' in source_resource) {
							let atlas = destination_subgroup.resource[(source_resource as ResourceManifest.SpriteImageResourceAdditional).parent];
							assert_test(atlas !== undefined, `sprite's parent is not found : ${source_resource.parent}`);
							assert_test(atlas.additional.type === 'atlas', `sprite's expand type is not 'atlas' : ${source_resource.parent}`);
							atlas.additional.value.sprite[source_resource.id] = {
								path: destination_resource_path,
								position: [
									JSONGenericGetter.integer(source_resource.ax),
									JSONGenericGetter.integer(source_resource.ay),
								],
								size: [
									JSONGenericGetter.integer(source_resource.aw),
									JSONGenericGetter.integer(source_resource.ah),
								],
								offset: [
									JSONGenericGetter.integer(source_resource.x, 0n),
									JSONGenericGetter.integer(source_resource.y, 0n),
								],
								layout: [
									JSONGenericGetter.integer(source_resource.cols, 1n),
									JSONGenericGetter.integer(source_resource.rows, 1n),
								],
							};
						} else {
							destination_subgroup.resource[source_resource.id] = {
								path: destination_resource_path,
								type: source_resource.type,
								additional: {
									type: 'generic',
									value: {
									},
								},
							};
						}
					}
					break;
				}
			}
		}
		return destination;
	}

	export function to_official(
		source: RegularResourceManifest.Package,
		use_array_style_path: boolean,
	): ResourceManifest.Package {
		let slot_map: Map<string, bigint> = new Map();
		let slot_of = (
			key: string,
		): bigint => {
			let value = slot_map.get(key);
			if (value === undefined) {
				value = BigInt(slot_map.size);
				slot_map.set(key, value);
			}
			return value;
		};
		let destination: ResourceManifest.Package = {
			slot_count: 0n,
			groups: [],
		};
		for (let group_id in source.group) {
			let source_group = source.group[group_id];
			let destination_group: null | (ResourceManifest.GroupBase & ResourceManifest.CompositeGroupAdditional) = null;
			if (source_group.composite) {
				destination_group = {
					id: group_id,
					type: 'composite',
					subgroups: [],
				};
				destination.groups.push(destination_group);
			}
			for (let subgroup_id in source_group.subgroup) {
				let source_subgroup = source_group.subgroup[subgroup_id];
				let destination_subgroup: ResourceManifest.GroupBase & ResourceManifest.SimpleGroupAdditional = {
					id: subgroup_id,
					type: 'simple',
				} as any;
				let category_property = {} as any;
				if (source_subgroup.category[0] !== null) {
					category_property.res = source_subgroup.category[0];
				}
				if (source_subgroup.category[1] !== null) {
					category_property.loc = source_subgroup.category[1];
				}
				Object.assign(destination_subgroup, category_property);
				if (source_group.composite) {
					destination_subgroup.parent = group_id;
					destination_group!.subgroups.push({
						id: subgroup_id,
						...category_property,
					});
				}
				destination_subgroup.resources = [];
				for (let resource_id in source_subgroup.resource) {
					let source_resource = source_subgroup.resource[resource_id];
					let destination_resource: ResourceManifest.Resource = {
						slot: slot_of(resource_id),
						id: resource_id,
						path: !use_array_style_path ? PathUtility.to_windows_style(source_resource.path) : PathUtility.split(source_resource.path),
						type: source_resource.type,
					} as ResourceManifest.Resource;
					destination_subgroup.resources.push(destination_resource);
					if (source_resource.additional.type === 'atlas') {
						(destination_resource as ResourceManifest.AtlasImageResourceAdditional).atlas = true;
						(destination_resource as ResourceManifest.AtlasImageResourceAdditional).width = source_resource.additional.value.size[0];
						(destination_resource as ResourceManifest.AtlasImageResourceAdditional).height = source_resource.additional.value.size[1];
						for (let sprite_resource_id in source_resource.additional.value.sprite) {
							let source_sprite_resource = source_resource.additional.value.sprite[sprite_resource_id];
							let destination_sprite_resource: ResourceManifest.ResourceBase & ResourceManifest.SpriteImageResourceAdditional = {
								slot: slot_of(sprite_resource_id),
								id: sprite_resource_id,
								path: !use_array_style_path ? PathUtility.to_windows_style(source_sprite_resource.path) : PathUtility.split(source_sprite_resource.path),
								type: 'Image',
								parent: resource_id,
								ax: source_sprite_resource.position[0],
								ay: source_sprite_resource.position[1],
								aw: source_sprite_resource.size[0],
								ah: source_sprite_resource.size[1],
								x: source_sprite_resource.offset[0],
								y: source_sprite_resource.offset[1],
								cols: source_sprite_resource.layout[0],
								rows: source_sprite_resource.layout[1],
							};
							destination_subgroup.resources.push(destination_sprite_resource);
						}
					}
				}
				destination.groups.push(destination_subgroup);
			}
		}
		destination.slot_count = BigInt(slot_map.size);
		return destination;
	}

	// ------------------------------------------------

}
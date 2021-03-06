﻿///////////////////////////////////////////////////////////////////////////////////////////////////
//LIGHTING
///////////////////////////////////////////////////////////////////////////////////////////////////
/*

OCCLUDER: Any object in scene that casts shadows
UMBRA: Region that is completely in shadow and fully occluded
PENUMBRA: Area outside the umbra that gradually softens with distance

3 POINT LIGHTING SETUP
KEY LIGHT: Light source the scheme is built around; main provider of light
FILL LIGHT: Helps control contrast by filling in dark shadows created by key light
BACK LIGHT: Defines the edge around the subject and seperates them from background

DEPTH OF FIELD
Smaller iris opening in camera = less exposure and light entering = more depth of field
Larger iris opening in camera = more exposure and light entering = less depth of field
Wide angle/short focal length lens = greater DOF
Narrow angle/long focal length lens = smaller DOF
Subject far away = greater DOF
Subject up close = smaller DOF

///////////////////////////////////////////////////////////////////////////////////////////////////
//LIGHT TYPES
///////////////////////////////////////////////////////////////////////////////////////////////////

DIRECTIONAL LIGHTS 
• Direction only
• Used to represent broad light source at a distance, illuminating whole scene
• Light moves in one direction, hitting surfaces, no attenuation used
• Not affected by attenuation and range

POINT/OMNI LIGHTS 
• Position only
• Emits light from all directions
• Affected by attenuation and range

SPOT LIGHTS 
• Direction and Position
• Emits light in one direction that spreads out as distance increases
• Affected by falloff, attenuation, and range and uses theta/phi values
• Vertex position within inner or outer cone is determined to determine the brightness
• THETA VALUE: Radian angle of the spotlight's inner cone (brightest)
• PHI VALUE: Radian angle for the outer cone of light
• FALLOFF: Controls how light intensity decreases between the outer and inner cones; set as 1 for even

BLOOM LIGHTS
• Glow around an object that resembles a halo
• Occurs when eyes/camera suddenly views a very bright object

LENS FLARE
• Scattered light reflected from within the cameras lens

LIGHT SHAFTS
• Light scatters off particles suspended in the media (Dust, water vapour)
• Occurs when light enters/exits materials such as a window
• Draw polygons emitting from light source and use additive blending
• As polygon's vertices become more distant from light they become more transparent

///////////////////////////////////////////////////////////////////////////////////////////////////
//DIRECT LIGHTING
///////////////////////////////////////////////////////////////////////////////////////////////////

EMISSIVE
• How much light is emitted from object

ATTENUATION
• How much light fades into distance
• Multiply by Specular/Diffuse models

LUMINANCE
• Intensity of light per unit area of its source

DIFFUSE
• The amount of light hitting a given point on a surface depends on the position
  of the lights around the surface and the direction the surface is facing.

SPECULAR
• Light reflecting near/exactly in the opposite direction of incoming light

REFLECTION:
• Rasterization uses reflection vector as set of coordinates to get colour from cube map. 
• Ray tracing uses primary ray which is reflected and used to trace the scene to see what the ray hits. 
• Colour chosen is combined with color of original object that was reflected

REFRACTION:
• When light passes through two different materials of different densities the light direction changes. 
• RI = Refractive index of material passing into

///////////////////////////////////////////////////////////////////////////////////////////////////
//INDIRECT LIGHTING
///////////////////////////////////////////////////////////////////////////////////////////////////

GLOBAL ILLUMINATION (INDIRECT LIGHTING): 
• Surfaces illuminated by light reflected off other surfaces
• Often stored in light maps due to being expensive to calculate

==============================================================================
INDIRECT LIGHTING EFFECTS FROM MATERIALS
==============================================================================
If a light bounces off a diffuse surface a color-bleeding happens.
If a light bounces off a specular surface a caustics reflection happens. 
If a light travels through a refracted surface a refracted caustics happens.
If a light is absorbed by a surface and leaves from opposite direction, subsurface scattering happens. 

COLOR/LIGHT BLEEDING: 
• Light that has reflected off one surface to another bringing
  with it some of its color which is seen on the second surface

CAUSTICS: 
• Reflection of light off a shiny object or focusing of light through a 
  transparent object to produce bright highlights on another object

SUBSURFACE SCATTERING: 
• Light enters, scatters around and leaves at a different point

AMBIENT LIGHTING:
• Light spread equally in all directions without falloff, constant value

==============================================================================
AMBIENT OCCLUSION
==============================================================================
• Used to define the occlusion amount of a point in the scene (vertex or pixel depending on precision)
• Each point sends multiple rays into the scene and tests for intersection against
  all geometry or can send out rays to test against itself for self shadowing
• Ratio of hits/misses is added and average float is found for that point
• Average multiplied by ambient light

==============================================================================
RADIOSITY
==============================================================================
• Considers everything a light source, and every surface can potentially light another surface
• Scene divided up into patches and view factor/form factor is computed for each patch compared to others
• Form factor describes how well patches can see each other; far away or obstructed means smaller factor
• Form factor used to generate the brightness of each patch taking into account diffuse/reflections/shadows

///////////////////////////////////////////////////////////////////////////////////////////////////
//MATERIALS
///////////////////////////////////////////////////////////////////////////////////////////////////

GOURAUD SHADING [DIFFUSE]: 
• Per-vertex diffuse lighting using linear interpolation of colour between verts

BLINN-PHONG SHADING [SPECULAR]: 
• Uses half-vector for specular calcuation

PHONG SHADING [SPECULAR]: 
• Uses reflection-vector for specular calcuation

BIDIRECTIONAL REFLECTANCE DISTRIBUTION FUNCTION (BRDF):
• Describes how an object reflects/absorbs light from different angles

CONDUCTIVE MATERIALS (metals)                    
• Reflections are tinted

DIELECTRICS (non-metals)
• Reflections are always white except when abosorption/transmission of light 
  occurs, tinting the light (ie. subsurface scattering)
 
FRESNAL RULE
• Gives the ratio of reflected/absorbed light for a surface

///////////////////////////////////////////////////////////////////////////////////////////////////
//HDR LIGHTING
///////////////////////////////////////////////////////////////////////////////////////////////////

TONE MAPPING
Maps the high dynamic range (HDR) of luminance values of real world lighting
to the limited range of the screen by dividing scene into set of zones.

  • Zone: range of luminance values
  • Middle gray: middle brightness region of the scene
  • Dynamic range: ratio of the highest scene luminance to the lowest scene luminance
  • Key: subjective measurement of scene lighting varying from light to dark
  
///////////////////////////////////////////////////////////////////////////////////////////////////
//SHADOW MAPPING
///////////////////////////////////////////////////////////////////////////////////////////////////

CREATING SHADOW MAP
• Look at scene from point of view of light source 
• Create shadow map via writing scene depth to rendertarget from the light's perspective

USING SHADOW MAP
• Transform vertex by light view projection matrix to get position in light space
• If depth in shadow map is /w, make sure /w for position in pixel shader
• Compare this to the position saved in the shadow map (also in light space)
• If depth is further away than the depth in shadow map the object is in shadow of another object

ADVANTAGES:
• Cheaper to use
• Easy to blur and make into soft shadows

DISADVANTAGES:  
• Dependent on size/depth of shadow map
• Suffers from artefacts/aliasing problems
• Stitching artifacts:
    - Occurs when depth value of shadow is close to surface
    - Solved by offsetting the shadow depth value retrieved by an amount
    - Solved by turning on front-face cull when creating shadow map

///////////////////////////////////////////////////////////////////////////////////////////////////
//SHADOW PROJECTION
///////////////////////////////////////////////////////////////////////////////////////////////////

• Shadow-projection matrix is created to scale anything rendered with it into a flat shape. 
• Light direction is used to control direction from which shadows appear once rendered. 
• The object is projected onto a plane then rendered as a separate primitive.

ADVANTAGES:     
• Easy to implement
• Doesn't require any hardware support such as shadow mapping
• Shadows can be created out of any object or an imposter can be used

DISADVANTAGES:  
• Doesn’t work well on specular surfaces 
• Difficult with non-flat surfaces, stencil buffer fixes this
• Can’t render self shadows
• Difficult to make into soft shadows
• Not a good representation of object
• z-fighting: 
    - close coplanar planes confuses the depth buffer for what to render first
    - Fixed by rendering at an offset or enabling hardware to take care of offset

///////////////////////////////////////////////////////////////////////////////////////////////////
//SHADOW VOLUMES
///////////////////////////////////////////////////////////////////////////////////////////////////

• Project the outline of an object into the scene based on the light position. 
• New geometry is created using this silhouette.

PIPELINE:
• Find the edges of an object that define the silhouette and create edge list
• Calculate new geometry from edge list and light vector and store into its own vertex buffer
• Create a counter that will increment/decrement for every surface rendered to the stencil buffer
• Render scene with back-face culling on; increment for every surface rendered
• Render with front-face culling on; decrement for every surface rendered
• If an object is within a shadow volume after two stencil tests the stencil buffer will have 1, if not, 0
• Clear the screen to black
• Render scene normally using results to only render to screen pixels set to 0, leaving sections with 1 black

CARMAK'S REVERSE:
If camera is inside a shadow volume counting for stencil buffers can be incorrect. 
Pixels that should not be in shadow are considered in shadow. Solution:  
  • Render with front-face culling first and increment stencil buffer whenever depth test fails
  • Render with back-face culling second and decrement stencil buffer whenever depth test fails

ADVANTAGES:     
• No aliasing/artefact problems
• Can self shadow
• More accurate representation of model

DISADVANTAGES:  
• Geometry dependent/expensive
• Requires additional data for quick determination of silhouette (object edge list)
• Difficult to make into soft shadows
 
///////////////////////////////////////////////////////////////////////////////////////////////////
//SOFT SHADOWS
///////////////////////////////////////////////////////////////////////////////////////////////////

SHADOW MAP: 
• Render only shadows from the shadow map onto a surface and blur using a bloom filter
• Scene rendered again blending the soft shadows into the scene

SHADOW PROJECTION/VOLUME:
• Use two objects: One for the umbra and one for penumbra, fading out penumbra 
• Jittering: Render the shadow more than once, each time in a 
  different position and blend with previous renders

*//////////////////////////////////////////////////////////////////////////////////////////////////
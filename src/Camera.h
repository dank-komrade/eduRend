
//
//  Camera.h
//
//	Basic camera class
//

#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "vec\vec.h"
#include "vec\mat.h"

using namespace linalg;

class Camera
{
public:
	// Aperture attributes
	float vfov, aspect;	
	
	// Clip planes in view space coordinates
	// Evrything outside of [zNear, zFar] is clipped away on the GPU side
	// zNear should be > 0
	// zFar should depend on the size of the scene
	// This range should be kept as tight as possibly to improve
	// numerical precision in the z-buffer
	float zNear, zFar;	
	vec3f position;
	float yaw, pinch = 0.0f;
	float scale = 0.005f;
	mat4f R;

	Camera(
		float vfov,
		float aspect,
		float zNear,
		float zFar):
		vfov(vfov), aspect(aspect), zNear(zNear), zFar(zFar)
	{
		position = {0.0f, 0.0f, 0.0f};
		
	}

	// Move to an absolute position
	//
	void moveTo(const vec3f& p)
	{
		position = p;
	}

	// Move relatively
	//
	void move(const vec3f& v)
	{
		/*position += v;*/
		position += (R * vec4f(v, 0)).xyz();
	}

	void UpdateX(long mousedx)
	{
		
		R = mat4f::rotation(0, yaw, pinch);
		yaw += mousedx * scale;
		
	}

	void UpdateY(long mousedy) {
		pinch = clamp(pinch, -PI / 2, PI / 2);
		R = mat4f::rotation(0, yaw, pinch);
		pinch += mousedy * scale;
	}

	void CameraMovement(vec3f& position, mat4f R) {
		position = (R * vec4f(position, 0)).xyz();
		
	}

	// Return World-to-View matrix for this camera
	//
	mat4f get_WorldToViewMatrix()
	{
		// Assuming a camera's position and rotation is defined by matrices T(p) and R,
		// the View-to-World transform is T(p)*R (for a first-person style camera).
		//
		// World-to-View then is the inverse of T(p)*R;
		//		inverse(T(p)*R) = inverse(R)*inverse(T(p)) = transpose(R)*T(-p)
		// Since now there is no rotation, this matrix is simply T(-p)

		return transpose(R) * mat4f::translation(-position);
	}

	mat4f get_ViewToWorldMatrix() 
	{
		return mat4f::translation(position) * R;
	}

	// Matrix transforming from View space to Clip space
	// In a performance sensitive situation this matrix should be precomputed
	// if possible
	//
	mat4f get_ProjectionMatrix()
	{
		return mat4f::projection(vfov, aspect, zNear, zFar);
	}

	vec4f get_Position()
	{
		return vec4f(position, 0);
	}
};

#endif
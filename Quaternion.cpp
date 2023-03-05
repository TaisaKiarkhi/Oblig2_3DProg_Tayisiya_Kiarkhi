#include "Quaternion.h"

Quaternion::Quaternion(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;

}

Quaternion::~Quaternion()
{
}

void Quaternion::matrix4x4SetIdentity(Matrix4x4 matIdent4x4)
{
	GLint row, column;

	for (row = 0; row < 4; row++) {
		for (column = 0; column < 4; column++) {
			matIdent4x4[row][column] = (row == column);
		}
	}

}

void Quaternion::translate3D(GLfloat tx, GLfloat ty, GLfloat tz)
{
	Matrix4x4 Transalted_Matrix;
	matrix4x4SetIdentity(Transalted_Matrix);

	Transalted_Matrix[0][3] = tx;
	Transalted_Matrix[1][3] = ty;
	Transalted_Matrix[2][3] = tz;

	matrix4X4PreMultiply(Transalted_Matrix, Matrix_Rotation);
}

void Quaternion::matrix4X4PreMultiply(Matrix4x4 mat1_, Matrix4x4 mat2_)
{
	GLint row, column;
	Matrix4x4 temp;
	GLfloat multiply;
	GLfloat sum = 0;

	for (row = 0; row < 4; row++) {
	for (int column_temp = 0; column_temp < 4; column_temp++) {
	for (column = 0; column < 4; column++) {
		multiply = mat1_[row][column] * mat2_[column][row];
		sum += multiply;
		}
	    temp[row][column_temp] = multiply;
		sum = 0;
		}
	}

	for (row = 0; row < 4; row++) {
	for (column = 0; column < 4; column++) {
		mat2_[row][column] = temp[row][column];
		}
	}
}

void Quaternion::rotate3D_Quaternion(glm::vec3 vert1, glm::vec3 vert2, GLfloat radians_angle)
{
	Matrix4x4 rotation_matrix_quaternion;
	
	GLfloat axis_vect_length = sqrt(pow((vert2.x - vert1.x), 2) + pow((vert2.y - vert1.y), 2) + pow((vert2.z - vert1.z), 2));
	GLfloat cos_a = cos(radians_angle);
	GLfloat sin_a = sin(radians_angle);
	GLfloat trigonom = 1 - cos_a;
    GLfloat ux = (vert2.x - vert1.x) / axis_vect_length;
    GLfloat uy = (vert2.y - vert1.y) / axis_vect_length;
    GLfloat uz = (vert2.z - vert1.z) / axis_vect_length;

	translate3D(-vert1.x, -vert1.y, -vert1.z); //translate to the origin

	matrix4x4SetIdentity(rotation_matrix_quaternion); //setting up the empty matrix to identity matrix

	rotation_matrix_quaternion[0][0] = pow(ux, 2) * trigonom + cos_a;
	rotation_matrix_quaternion[0][1] = (ux * uy * trigonom) - (uz * sin_a);
	rotation_matrix_quaternion[0][2] = (ux * uz * trigonom) + (uy * sin_a);
	rotation_matrix_quaternion[1][0] = (uy * ux * trigonom) + (uz * sin_a);
	rotation_matrix_quaternion[1][1] = pow(uy, 2) * trigonom + cos_a;
	rotation_matrix_quaternion[1][2] = (uy * uz * trigonom) - ux * sin_a;
	rotation_matrix_quaternion[2][0] = (uz * uy * trigonom) - uy * sin_a;
	rotation_matrix_quaternion[2][1] = (uz * uy * trigonom) + ux * sin_a;
	rotation_matrix_quaternion[2][2] = pow(uz, 2) * trigonom + cos_a;

	matrix4X4PreMultiply(rotation_matrix_quaternion, Matrix_Rotation); //multiply quaternion rotation with translated matrix

	translate3D(vert1.x, vert1.y,vert1.z); //inverse translation to bring the everything back
}

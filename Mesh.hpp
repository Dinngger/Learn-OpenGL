#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Shader.hpp"

class Mesh {
public:
    std::vector<glm::vec3> vertices;
    std::vector<uint> indices;
    void draw() {
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0);
    }
    int loadFile(std::string filepath) {
        std::ifstream inFile(filepath);
        if (inFile.fail()) {
            printf("open file %s error\n", filepath.c_str());
            return -1;
        }
        vertices.clear();
        indices.clear();
        int vertices_size = -1, faces_size = -1;
        inFile >> vertices_size;
        inFile >> faces_size;
        vertices.resize(vertices_size);
        indices.resize(faces_size * 3);
        for (int i=0; i<vertices_size; i++) {
            glm::vec3 v;
            inFile >> v.x >> v.y >> v.z;
            vertices[i] = v;
        }
        for (int i=0; i<faces_size; i++) {
            glm::uvec3 f;
            inFile >> f.x >> f.y >> f.z;
            indices[i*3] = f.x;
            indices[i*3+1] = f.y;
            indices[i*3+2] = f.z;
        }
        setupMesh();
        printf("read file finished\n");
        return 0;
    }
    void deleteBuffer() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
private:
    uint VAO, VBO, EBO;
    void setupMesh() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(0);
    }
};

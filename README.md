# PLADE : Play & Code
## Overview

PLADE is an AI-powered interactive application designed to make coding and problem-solving more engaging through a game-based environment. Instead of relying on static questions or traditional learning platforms, PLADE allows users to interact with systems, solve logic-based challenges, and improve their debugging skills in real time.

---
## Note
This project was developed as part of a hackathon, focusing on the integration of artificial intelligence with interactive application design.
Note : The project was initially developed using Blueprint Visual Scripting and later converted into C++ for improved control and maintainability. This repository contains only the core logic (C++ and AI components). Textures, maps, and 3D assets have been intentionally excluded to reduce repository size, protect project assets, and prevent unauthorized reuse or replication.

## Core Concept

PLADE redefines coding practice by embedding it into an interactive environment:

* Users interact with systems instead of static problem sets
* Debugging and logical reasoning are part of the experience
* AI dynamically evaluates inputs and generates contextual responses

---

## Tech Stack

### Application Layer

* Unreal Engine 5.4 (Game Engine)
* Blueprint logic converted to C++ for scalability and version control
* Fab Marketplace 3D Models (Open Source)

### Backend & AI System

* Node.js (AI server and API handling)
* TinyLlama (lightweight LLM for fast inference)
* Retrieval-Augmented Generation (RAG pipeline)

### Knowledge Base

* Structured text data (`knowledge.txt` and related files)
* Used for context retrieval and grounding AI responses

---

## Key Features

### Gamified Problem Solving

* Interactive challenges requiring logic and debugging
* Simulates real-world coding scenarios

### AI-Driven Interaction

* Context-aware response generation
* Adaptive feedback based on user input
* Reduced hallucination through retrieval grounding

### Real-Time Feedback

* Immediate response loop between application and AI system

---

## System Architecture

* Unreal Engine (C++) handles gameplay and user interaction
* Node.js server acts as the bridge between game and AI
* TinyLlama processes prompts and generates responses
* Knowledge base provides contextual grounding

---

## RAG Pipeline Flow

1. User performs an action or submits input inside the application
2. Input is sent to the Node.js backend
3. Backend processes the query:

   * Parses user intent
   * Searches relevant data from knowledge base (`knowledge.txt`)
4. Retrieved context is combined with the user query
5. Final prompt is sent to TinyLlama
6. TinyLlama generates a context-aware response
7. Response is sent back to the application
8. Application updates behavior or provides feedback to the user

This ensures responses are:

* Contextual
* Relevant
* Grounded in predefined knowledge

---

## Repository Structure

```id="t8k92p"
/CPP_Code     → Unreal Engine C++ source files  
/AI_Server    → Node.js backend and RAG implementation  
/Docs         → Supporting documentation (if applicable)  
```

**Note:**
This repository contains only core logic and AI components.
Assets such as textures, maps, and models are excluded.

---

## Problem Statement

Traditional coding platforms lack interactivity and adaptability, resulting in low engagement and limited practical understanding.

---

## Proposed Solution

PLADE addresses this by:

* Integrating learning into an interactive environment
* Using AI for dynamic and personalized responses
* Providing real-time feedback through a RAG-based system

---

## Future Scope

* Multiplayer environments
* Improved retrieval systems (vector databases)
* More advanced AI models
* Expanded problem scenarios

---

## Author

Zency Studios <3
---

## Conclusion

PLADE demonstrates how combining AI with interactive systems can create a more effective and engaging approach to learning coding and problem-solving.

#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Astar.o \
	${OBJECTDIR}/Bitmasks.o \
	${OBJECTDIR}/Box.o \
	${OBJECTDIR}/Bullet.o \
	${OBJECTDIR}/Clock.o \
	${OBJECTDIR}/Door.o \
	${OBJECTDIR}/Enemy.o \
	${OBJECTDIR}/EnemyBounce.o \
	${OBJECTDIR}/EnemyChase.o \
	${OBJECTDIR}/EnemyStand.o \
	${OBJECTDIR}/Event.o \
	${OBJECTDIR}/Font.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/Hud.o \
	${OBJECTDIR}/Image.o \
	${OBJECTDIR}/Input.o \
	${OBJECTDIR}/LevelFactory.o \
	${OBJECTDIR}/Message.o \
	${OBJECTDIR}/Node.o \
	${OBJECTDIR}/Object.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/PowerUp.o \
	${OBJECTDIR}/RenderWindow.o \
	${OBJECTDIR}/Situation.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/StateGameLoop.o \
	${OBJECTDIR}/StateGameOver.o \
	${OBJECTDIR}/StateStart.o \
	${OBJECTDIR}/Switch.o \
	${OBJECTDIR}/Text.o \
	${OBJECTDIR}/Texture.o \
	${OBJECTDIR}/View.o \
	${OBJECTDIR}/World.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/tinyxml2.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafv

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafv: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicafv ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Astar.o: Astar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Astar.o Astar.cpp

${OBJECTDIR}/Bitmasks.o: Bitmasks.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bitmasks.o Bitmasks.cpp

${OBJECTDIR}/Box.o: Box.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Box.o Box.cpp

${OBJECTDIR}/Bullet.o: Bullet.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bullet.o Bullet.cpp

${OBJECTDIR}/Clock.o: Clock.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clock.o Clock.cpp

${OBJECTDIR}/Door.o: Door.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Door.o Door.cpp

${OBJECTDIR}/Enemy.o: Enemy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemy.o Enemy.cpp

${OBJECTDIR}/EnemyBounce.o: EnemyBounce.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EnemyBounce.o EnemyBounce.cpp

${OBJECTDIR}/EnemyChase.o: EnemyChase.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EnemyChase.o EnemyChase.cpp

${OBJECTDIR}/EnemyStand.o: EnemyStand.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EnemyStand.o EnemyStand.cpp

${OBJECTDIR}/Event.o: Event.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Event.o Event.cpp

${OBJECTDIR}/Font.o: Font.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Font.o Font.cpp

${OBJECTDIR}/Game.o: Game.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/Hud.o: Hud.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hud.o Hud.cpp

${OBJECTDIR}/Image.o: Image.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Image.o Image.cpp

${OBJECTDIR}/Input.o: Input.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Input.o Input.cpp

${OBJECTDIR}/LevelFactory.o: LevelFactory.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LevelFactory.o LevelFactory.cpp

${OBJECTDIR}/Message.o: Message.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Message.o Message.cpp

${OBJECTDIR}/Node.o: Node.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Node.o Node.cpp

${OBJECTDIR}/Object.o: Object.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Object.o Object.cpp

${OBJECTDIR}/Player.o: Player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/PowerUp.o: PowerUp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PowerUp.o PowerUp.cpp

${OBJECTDIR}/RenderWindow.o: RenderWindow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RenderWindow.o RenderWindow.cpp

${OBJECTDIR}/Situation.o: Situation.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Situation.o Situation.cpp

${OBJECTDIR}/Sprite.o: Sprite.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/State.o: State.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/StateGameLoop.o: StateGameLoop.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateGameLoop.o StateGameLoop.cpp

${OBJECTDIR}/StateGameOver.o: StateGameOver.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateGameOver.o StateGameOver.cpp

${OBJECTDIR}/StateStart.o: StateStart.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateStart.o StateStart.cpp

${OBJECTDIR}/Switch.o: Switch.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Switch.o Switch.cpp

${OBJECTDIR}/Text.o: Text.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Text.o Text.cpp

${OBJECTDIR}/Texture.o: Texture.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Texture.o Texture.cpp

${OBJECTDIR}/View.o: View.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/View.o View.cpp

${OBJECTDIR}/World.o: World.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/World.o World.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/tinyxml2.o: tinyxml2.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml2.o tinyxml2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

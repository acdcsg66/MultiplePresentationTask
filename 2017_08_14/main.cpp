#include "InitSettings.h"
#include "Tutorial.h"
#include "NumGenerator.h"
#include "Experiment.h"

int main() {

	InitSettings is;
	Tutorial t;
	Experiment e;

	is.initSet();
	t.showTutorial();
	e.experiment();
}
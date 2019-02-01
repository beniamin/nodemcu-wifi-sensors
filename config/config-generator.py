from string import Template
from environment import config
import sys

Import("env")

tPath = env["PROJECT_DIR"] + "/config/Config.h.tpl"
oPath = env["PROJECT_DIR"] + "/src/Config.h"
print "Start generating config " + oPath + " from template " + tPath + "\n"
template = Template(open(tPath, 'r').read())
outFile = open(oPath, "w+")

result = template.substitute(config)

outFile.write(result)

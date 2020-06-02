#!/usr/bin/env python
# -*- coding: utf-8 -*-

# The ue_site.py python file gets executed on launch every time you start the engine, so any function you want on startup
# All our main code is called from ms_setup.py.

import unreal_engine as ue
ue.exec("ms_setup.py")

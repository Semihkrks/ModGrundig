import sys
import gdb

# Update module path.
dir = '/home/derek.li/release_glib/release_libraries_m432/share/glib-2.0/gdb'
if not dir in sys.path:
    sys.path.insert(0, dir)

from gobject import register
register (gdb.current_objfile ())

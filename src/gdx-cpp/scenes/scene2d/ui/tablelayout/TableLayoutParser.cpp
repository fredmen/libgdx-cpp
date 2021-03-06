
/*
    Copyright 2011 Aevum Software aevum @ aevumlab.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    @author Victor Vicente de Carvalho victor.carvalho@aevumlab.com
    @author Ozires Bortolon de Faria ozires@aevumlab.com
*/

#include "TableLayoutParser.hpp"

using namespace gdx_cpp::scenes::scene2d::ui::tablelayout;

void TableLayoutParser::parse (const BaseTableLayout& table,const std::string& input) {
    Toolkit toolkit = table.toolkit;

    char[] data = (input + "  ").toCharArray();
    int cs, p = 0, pe = data.length, eof = pe, top = 0;
    int[] stack = new int[4];

    int s = 0;
    String name = null;
    String widgetLayoutString = null;
    String className = null;

    int columnDefaultCount = 0;
    ArrayList<String> values = new ArrayList(4);
    ArrayList<Object> parents = new ArrayList(8);
    Cell cell = null, rowDefaults = null, columnDefaults = null;
    Object parent = table, widget = null;
    RuntimeException parseRuntimeEx = null;
    boolean hasColon = false;

    boolean debug = false;
    if (debug) System.out.println();

    try {

        // line 3 "../src/com/esotericsoftware/tablelayout/TableLayoutParser.java"
        {
            cs = tableLayout_start;
            top = 0;
        }

        // line 8 "../src/com/esotericsoftware/tablelayout/TableLayoutParser.java"
        {
            int _klen;
            int _trans = 0;
            int _acts;
            int _nacts;
            int _keys;
            int _goto_targ = 0;

_goto:
            while (true) {
                switch (_goto_targ) {
                case 0:
                    if (p == pe) {
                        _goto_targ = 4;
                        continue _goto;
                    }
                    if (cs == 0) {
                        _goto_targ = 5;
                        continue _goto;
                    }
                case 1:
_match:
                    do {
                        _keys = _tableLayout_key_offsets[cs];
                        _trans = _tableLayout_index_offsets[cs];
                        _klen = _tableLayout_single_lengths[cs];
                        if (_klen > 0) {
                            int _lower = _keys;
                            int _mid;
                            int _upper = _keys + _klen - 1;
                            while (true) {
                                if (_upper < _lower) break;

                                _mid = _lower + ((_upper - _lower) >> 1);
                                if (data[p] < _tableLayout_trans_keys[_mid])
                                    _upper = _mid - 1;
                                else if (data[p] > _tableLayout_trans_keys[_mid])
                                    _lower = _mid + 1;
                                else {
                                    _trans += (_mid - _keys);
                                    break _match;
                                }
                            }
                            _keys += _klen;
                            _trans += _klen;
                        }

                        _klen = _tableLayout_range_lengths[cs];
                        if (_klen > 0) {
                            int _lower = _keys;
                            int _mid;
                            int _upper = _keys + (_klen << 1) - 2;
                            while (true) {
                                if (_upper < _lower) break;

                                _mid = _lower + (((_upper - _lower) >> 1) & ~1);
                                if (data[p] < _tableLayout_trans_keys[_mid])
                                    _upper = _mid - 2;
                                else if (data[p] > _tableLayout_trans_keys[_mid + 1])
                                    _lower = _mid + 2;
                                else {
                                    _trans += ((_mid - _keys) >> 1);
                                    break _match;
                                }
                            }
                            _trans += _klen;
                        }
                    } while (false);

                    cs = _tableLayout_trans_targs[_trans];

                    if (_tableLayout_trans_actions[_trans] != 0) {
                        _acts = _tableLayout_trans_actions[_trans];
                        _nacts = (int)_tableLayout_actions[_acts++];
                        while (_nacts-- > 0) {
                            switch (_tableLayout_actions[_acts++]) {
                            case 0:
                                // line 43 "TableLayoutParser.rl"
                            {
                                s = p;
                            }
                            break;
                            case 1:
                                // line 44 "TableLayoutParser.rl"
                            {
                                name = new String(data, s, p - s);
                                s = p;
                            }
                            break;
                            case 2:
                                // line 48 "TableLayoutParser.rl"
                            {
                                values.add(new String(data, s, p - s));
                            }
                            break;
                            case 3:
                                // line 51 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("tableProperty: " + name + " = " + values);
                                toolkit.setTableProperty((BaseTableLayout)parent, name, values);
                                values.clear();
                                name = null;
                            }
                            break;
                            case 4:
                                // line 57 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("cellDefaultProperty: " + name + " = " + values);
                                toolkit.setCellProperty(((BaseTableLayout)parent).defaults(), name, values);
                                values.clear();
                                name = null;
                            }
                            break;
                            case 5:
                                // line 63 "TableLayoutParser.rl"
                            {
                                columnDefaults = ((BaseTableLayout)parent).columnDefaults(columnDefaultCount++);
                            }
                            break;
                            case 6:
                                // line 66 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("columnDefaultProperty: " + name + " = " + values);
                                toolkit.setCellProperty(columnDefaults, name, values);
                                values.clear();
                                name = null;
                            }
                            break;
                            case 7:
                                // line 72 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("startRow");
                                rowDefaults = ((BaseTableLayout)parent).row();
                            }
                            break;
                            case 8:
                                // line 76 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("rowDefaultValue: " + name + " = " + values);
                                toolkit.setCellProperty(rowDefaults, name, values);
                                values.clear();
                                name = null;
                            }
                            break;
                            case 9:
                                // line 82 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("cellProperty: " + name + " = " + values);
                                toolkit.setCellProperty(cell, name, values);
                                values.clear();
                                name = null;
                            }
                            break;
                            case 10:
                                // line 88 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("widgetLayoutString: " + new String(data, s, p - s).trim());
                                widgetLayoutString = new String(data, s, p - s).trim();
                            }
                            break;
                            case 11:
                                // line 92 "TableLayoutParser.rl"
                            {
                                className = new String(data, s, p - s);
                            }
                            break;
                            case 12:
                                // line 95 "TableLayoutParser.rl"
                            {
                                if (debug)
                                    System.out.println("newWidget, name:" + name + " class:" + className + " widget:" + widget);
                                if (widget != null) { // 'label' or ['label'] or [name:'label']
                                    if (name != null && name.length() > 0) table.register(name, widget);
                                } else if (className == null) {
                                    if (name.length() > 0) {
                                        if (hasColon) { // [name:]
                                            widget = toolkit.wrap(null);
                                            table.register(name, widget);
                                        } else { // [name]
                                            widget = table.getWidget(name);
                                            if (widget == null) {
                                                // Try the widget name as a class name.
                                                try {
                                                    widget = toolkit.newWidget(table, name);
                                                } catch (RuntimeException ex) {
                                                    throw new IllegalArgumentException("Widget not found with name: " + name);
                                                }
                                            }
                                        }
                                    } else
                                        // []
                                        widget = toolkit.wrap(null);
                                } else { // [:class] and [name:class]
                                    widget = toolkit.newWidget(table, className);
                                    if (name.length() > 0) table.register(name, widget);
                                }
                                name = null;
                                className = null;
                            }
                            break;
                            case 13:
                                // line 124 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("newLabel: " + new String(data, s, p - s));
                                widget = toolkit.wrap(new String(data, s, p - s));
                            }
                            break;
                            case 14:
                                // line 128 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("startTable, name:" + name);
                                parents.add(parent);
                                BaseTableLayout parentTable = null;
                                for (int i = parents.size() - 1; i >= 0; i--) {
                                    Object object = parents.get(i);
                                    if (object instanceof BaseTableLayout) {
                                        parentTable = (BaseTableLayout)object;
                                        break;
                                    }
                                }
                                if (parentTable == null) parentTable = table;
                                parent = toolkit.getLayout(toolkit.newTable(parentTable.getTable()));
                                ((BaseTableLayout)parent).setParent(parentTable);
                                if (name != null) { // [name:{}]
                                    table.register(name, ((BaseTableLayout)parent).getTable());
                                    name = null;
                                }
                                cell = null;
                                widget = null;
                                {
                                    if (top == stack.length) {
                                        int[] newStack = new int[stack.length * 2];
                                        System.arraycopy(stack, 0, newStack, 0, stack.length);
                                        stack = newStack;
                                    }
                                    {
                                        stack[top++] = cs;
                                        cs = 62;
                                        _goto_targ = 2;
                                        if (true) continue _goto;
                                    }
                                }
                            }
                            break;
                            case 15:
                                // line 150 "TableLayoutParser.rl"
                            {
                                widget = parent;
                                if (!parents.isEmpty()) {
                                    if (debug) System.out.println("endTable");
                                    parent = parents.remove(parents.size() - 1);
                                    {
                                        cs = stack[--top];
                                        _goto_targ = 2;
                                        if (true) continue _goto;
                                    }
                                }
                            }
                            break;
                            case 16:
                                // line 158 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("startStack, name:" + name);
                                parents.add(parent);
                                parent = toolkit.newStack();
                                if (name != null) { // [name:<>]
                                    table.register(name, parent);
                                    name = null;
                                }
                                cell = null;
                                widget = null;
                                {
                                    if (top == stack.length) {
                                        int[] newStack = new int[stack.length * 2];
                                        System.arraycopy(stack, 0, newStack, 0, stack.length);
                                        stack = newStack;
                                    }
                                    {
                                        stack[top++] = cs;
                                        cs = 91;
                                        _goto_targ = 2;
                                        if (true) continue _goto;
                                    }
                                }
                            }
                            break;
                            case 17:
                                // line 170 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("endStack");
                                widget = parent;
                                parent = parents.remove(parents.size() - 1);
                                {
                                    cs = stack[--top];
                                    _goto_targ = 2;
                                    if (true) continue _goto;
                                }
                            }
                            break;
                            case 18:
                                // line 176 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("startWidgetSection");
                                parents.add(parent);
                                parent = widget;
                                widget = null;
                                {
                                    if (top == stack.length) {
                                        int[] newStack = new int[stack.length * 2];
                                        System.arraycopy(stack, 0, newStack, 0, stack.length);
                                        stack = newStack;
                                    }
                                    {
                                        stack[top++] = cs;
                                        cs = 68;
                                        _goto_targ = 2;
                                        if (true) continue _goto;
                                    }
                                }
                            }
                            break;
                            case 19:
                                // line 183 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("endWidgetSection");
                                widget = parent;
                                parent = parents.remove(parents.size() - 1);
                                {
                                    cs = stack[--top];
                                    _goto_targ = 2;
                                    if (true) continue _goto;
                                }
                            }
                            break;
                            case 20:
                                // line 189 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("addCell");
                                cell = ((BaseTableLayout)parent).add(toolkit.wrap(widget));
                            }
                            break;
                            case 21:
                                // line 193 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("addWidget");
                                toolkit.addChild(parent, toolkit.wrap(widget), widgetLayoutString);
                                widgetLayoutString = null;
                            }
                            break;
                            case 22:
                                // line 198 "TableLayoutParser.rl"
                            {
                                if (debug) System.out.println("widgetProperty: " + name + " = " + values);
                                Object propertyTarget = parent;
                                if (parent instanceof BaseTableLayout) propertyTarget = ((BaseTableLayout)parent).getTable();
                                toolkit.setProperty(table, propertyTarget, name, values);
                                values.clear();
                                name = null;
                            }
                            break;
                            case 23:
                                // line 218 "TableLayoutParser.rl"
                            {
                                widget = null;
                                hasColon = false;
                            }
                            break;
                            case 24:
                                // line 219 "TableLayoutParser.rl"
                            {
                                hasColon = true;
                            }
                            break;
                            // line 346 "../src/com/esotericsoftware/tablelayout/TableLayoutParser.java"
                            }
                        }
                    }

                case 2:
                    if (cs == 0) {
                        _goto_targ = 5;
                        continue _goto;
                    }
                    if (++p != pe) {
                        _goto_targ = 1;
                        continue _goto;
                    }
                case 4:
                case 5:
                }
                break;
            }
        }

        // line 278 "TableLayoutParser.rl"

    } catch (RuntimeException ex) {
        parseRuntimeEx = ex;
    }

    if (p < pe) {
        int lineNumber = 1;
        int lineStartOffset = 0;
        for (int i = 0; i < p; i++) {
            if (data[i] == '\n') {
                lineNumber++;
                lineStartOffset = i;
            }
        }
        ParseException ex = new ParseException("Error parsing layout on line " + lineNumber + ":" + (p - lineStartOffset)
                                               + " near: " + new String(data, p, Math.min(64, pe - p)), parseRuntimeEx);
        ex.line = lineNumber;
        ex.column = p - lineStartOffset;
        throw ex;
    } else if (top > 0)
        throw new ParseException("Error parsing layout (possibly an unmatched brace or quote): "
                                 + new String(data, 0, Math.min(64, pe)), parseRuntimeEx);
}

char* TableLayoutParser::init__tableLayout_actions_0 () {
    return new byte[] {0, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16,
                       1, 17, 1, 18, 1, 19, 1, 20, 1, 21, 1, 22, 1, 23, 2, 0, 2, 2, 0, 11, 2, 0, 13, 2, 1, 3, 2, 1, 4, 2, 1, 6, 2, 1, 8, 2, 1,
                       9, 2, 1, 12, 2, 1, 22, 2, 1, 24, 2, 2, 3, 2, 2, 4, 2, 2, 6, 2, 2, 8, 2, 2, 9, 2, 2, 22, 2, 3, 14, 2, 3, 15, 2, 3, 16, 2,
                       3, 23, 2, 4, 14, 2, 4, 15, 2, 4, 16, 2, 4, 23, 2, 5, 0, 2, 5, 14, 2, 5, 15, 2, 5, 16, 2, 5, 23, 2, 6, 14, 2, 6, 15, 2,
                       6, 16, 2, 6, 23, 2, 7, 0, 2, 7, 14, 2, 7, 16, 2, 7, 23, 2, 8, 14, 2, 8, 16, 2, 8, 23, 2, 9, 14, 2, 9, 15, 2, 9, 16, 2,
                       9, 18, 2, 9, 23, 2, 10, 21, 2, 11, 12, 2, 16, 0, 2, 20, 0, 2, 20, 14, 2, 20, 15, 2, 20, 16, 2, 20, 18, 2, 20, 23, 2, 21,
                       14, 2, 21, 16, 2, 21, 17, 2, 21, 18, 2, 21, 19, 2, 21, 23, 2, 22, 14, 2, 22, 16, 2, 22, 19, 2, 22, 23, 3, 0, 1, 12, 3,
                       0, 1, 24, 3, 1, 3, 14, 3, 1, 3, 15, 3, 1, 3, 16, 3, 1, 3, 23, 3, 1, 4, 14, 3, 1, 4, 15, 3, 1, 4, 16, 3, 1, 4, 23, 3, 1,
                       6, 14, 3, 1, 6, 15, 3, 1, 6, 16, 3, 1, 6, 23, 3, 1, 8, 14, 3, 1, 8, 16, 3, 1, 8, 23, 3, 1, 9, 14, 3, 1, 9, 15, 3, 1, 9,
                       16, 3, 1, 9, 18, 3, 1, 9, 23, 3, 1, 22, 14, 3, 1, 22, 16, 3, 1, 22, 19, 3, 1, 22, 23, 3, 2, 3, 14, 3, 2, 3, 15, 3, 2, 3,
                       16, 3, 2, 3, 23, 3, 2, 4, 14, 3, 2, 4, 15, 3, 2, 4, 16, 3, 2, 4, 23, 3, 2, 6, 14, 3, 2, 6, 15, 3, 2, 6, 16, 3, 2, 6, 23,
                       3, 2, 8, 14, 3, 2, 8, 16, 3, 2, 8, 23, 3, 2, 9, 14, 3, 2, 9, 15, 3, 2, 9, 16, 3, 2, 9, 18, 3, 2, 9, 23, 3, 2, 22, 14, 3,
                       2, 22, 16, 3, 2, 22, 19, 3, 2, 22, 23, 3, 10, 21, 14, 3, 10, 21, 16, 3, 10, 21, 18, 3, 10, 21, 19, 3, 10, 21, 23
                      };
}

short* TableLayoutParser::init__tableLayout_key_offsets_0 () {
    return new short[] {0, 0, 17, 18, 19, 35, 51, 60, 61, 62, 75, 82, 87, 89, 97, 104, 112, 113, 114, 118, 132, 146, 163, 174,
                        175, 176, 184, 193, 210, 227, 241, 261, 272, 273, 274, 285, 294, 303, 320, 337, 351, 371, 387, 403, 419, 436, 453, 467,
                        487, 498, 499, 500, 511, 520, 531, 532, 533, 544, 553, 571, 589, 603, 624, 641, 652, 653, 654, 666, 675, 689, 690, 691,
                        706, 714, 719, 721, 729, 736, 744, 745, 746, 750, 765, 780, 795, 809, 827, 838, 839, 840, 849, 858, 866, 867, 868, 877,
                        886, 891, 893, 901, 908, 916, 917, 918, 922, 925, 925
                       };
}

char* TableLayoutParser::init__tableLayout_trans_keys_0 () {
    return new char[] {32, 39, 42, 45, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39, 40, 45, 60, 91,
                       123, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 40, 45, 60, 91, 123, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 45,
                       60, 91, 123, 125, 9, 13, 45, 45, 32, 39, 60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 60, 91, 123, 9, 13, 32,
                       58, 93, 9, 13, 58, 93, 32, 39, 58, 60, 93, 123, 9, 13, 32, 39, 58, 93, 123, 9, 13, 32, 39, 58, 60, 93, 123, 9, 13, 39,
                       39, 32, 93, 9, 13, 32, 39, 58, 60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 45, 46, 95, 9, 13, 48, 57, 65,
                       90, 97, 122, 32, 37, 39, 44, 46, 60, 91, 95, 123, 9, 13, 48, 57, 65, 90, 97, 122, 37, 39, 45, 46, 95, 48, 57, 65, 90,
                       97, 122, 39, 39, 32, 39, 44, 60, 91, 123, 9, 13, 37, 46, 95, 48, 57, 65, 90, 97, 122, 32, 39, 40, 45, 58, 60, 91, 123,
                       125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 40, 45, 58, 60, 91, 123, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39,
                       45, 46, 95, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 40, 44, 45, 46, 60, 91, 95, 123, 125, 9, 13, 48, 57, 65, 90, 97,
                       122, 37, 39, 45, 46, 95, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39, 40, 44, 45, 60, 91, 123, 125, 9, 13, 37, 46, 95, 48,
                       57, 65, 90, 97, 122, 32, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 45, 58, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90,
                       97, 122, 32, 39, 45, 58, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 45, 46, 95, 9, 13, 48, 57,
                       65, 90, 97, 122, 32, 37, 39, 44, 45, 46, 60, 91, 95, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 45, 60, 91,
                       123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 45, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32,
                       39, 45, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 45, 58, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65,
                       90, 97, 122, 32, 39, 45, 58, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 45, 46, 95, 9, 13, 48,
                       57, 65, 90, 97, 122, 32, 37, 39, 44, 45, 46, 60, 91, 95, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 37, 39, 45, 46,
                       95, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39, 44, 45, 60, 91, 123, 124, 125, 9, 13, 37, 46, 95, 48, 57, 65, 90, 97, 122,
                       37, 39, 45, 46, 95, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39, 44, 45, 60, 91, 123, 124, 125, 9, 13, 37, 46, 95, 48, 57,
                       65, 90, 97, 122, 32, 39, 42, 45, 58, 60, 91, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 42, 45, 58, 60, 91,
                       123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 45, 46, 95, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 42,
                       44, 45, 46, 60, 91, 95, 123, 124, 125, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 42, 45, 60, 91, 123, 124, 125, 9, 13, 48,
                       57, 65, 90, 97, 122, 37, 39, 45, 46, 95, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39, 42, 44, 45, 60, 91, 123, 124, 125, 9,
                       13, 37, 46, 95, 48, 57, 65, 90, 97, 122, 32, 39, 41, 60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39, 40,
                       41, 60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 41, 60, 91, 123, 9, 13, 32, 58, 93, 9, 13, 58, 93, 32, 39, 58,
                       60, 93, 123, 9, 13, 32, 39, 58, 93, 123, 9, 13, 32, 39, 58, 60, 93, 123, 9, 13, 39, 39, 32, 93, 9, 13, 32, 39, 40, 41,
                       60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 41, 58, 60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 32, 39, 41,
                       58, 60, 91, 123, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 45, 46, 95, 9, 13, 48, 57, 65, 90, 97, 122, 32, 37, 39, 41,
                       44, 46, 60, 91, 95, 123, 9, 13, 48, 57, 65, 90, 97, 122, 37, 39, 45, 46, 95, 48, 57, 65, 90, 97, 122, 39, 39, 32, 39,
                       41, 44, 60, 91, 123, 9, 13, 37, 46, 95, 48, 57, 65, 90, 97, 122, 32, 39, 60, 62, 91, 123, 9, 13, 39, 39, 32, 39, 40, 60,
                       62, 91, 123, 9, 13, 32, 39, 40, 60, 62, 91, 123, 9, 13, 32, 58, 93, 9, 13, 58, 93, 32, 39, 58, 60, 93, 123, 9, 13, 32,
                       39, 58, 93, 123, 9, 13, 32, 39, 58, 60, 93, 123, 9, 13, 39, 39, 32, 93, 9, 13, 32, 9, 13, 0
                      };
}

char* TableLayoutParser::init__tableLayout_single_lengths_0 () {
    return new byte[] {0, 9, 1, 1, 8, 8, 7, 1, 1, 5, 5, 3, 2, 6, 5, 6, 1, 1, 2, 6, 6, 9, 5, 1, 1, 6, 3, 9, 9, 6, 12, 5, 1, 1,
                       9, 3, 1, 9, 9, 6, 12, 8, 8, 8, 9, 9, 6, 12, 5, 1, 1, 9, 3, 5, 1, 1, 9, 3, 10, 10, 6, 13, 9, 5, 1, 1, 10, 3, 6, 1, 1, 7,
                       6, 3, 2, 6, 5, 6, 1, 1, 2, 7, 7, 7, 6, 10, 5, 1, 1, 7, 3, 6, 1, 1, 7, 7, 3, 2, 6, 5, 6, 1, 1, 2, 1, 0, 0
                      };
}

char* TableLayoutParser::init__tableLayout_range_lengths_0 () {
    return new byte[] {0, 4, 0, 0, 4, 4, 1, 0, 0, 4, 1, 1, 0, 1, 1, 1, 0, 0, 1, 4, 4, 4, 3, 0, 0, 1, 3, 4, 4, 4, 4, 3, 0, 0, 1,
                       3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 0, 0, 1, 3, 3, 0, 0, 1, 3, 4, 4, 4, 4, 4, 3, 0, 0, 1, 3, 4, 0, 0, 4, 1, 1, 0,
                       1, 1, 1, 0, 0, 1, 4, 4, 4, 4, 4, 3, 0, 0, 1, 3, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0
                      };
}

short* TableLayoutParser::init__tableLayout_index_offsets_0 () {
    return new short[] {0, 0, 14, 16, 18, 31, 44, 53, 55, 57, 67, 74, 79, 82, 90, 97, 105, 107, 109, 113, 124, 135, 149, 158,
                        160, 162, 170, 177, 191, 205, 216, 233, 242, 244, 246, 257, 264, 270, 284, 298, 309, 326, 339, 352, 365, 379, 393, 404,
                        421, 430, 432, 434, 445, 452, 461, 463, 465, 476, 483, 498, 513, 524, 542, 556, 565, 567, 569, 581, 588, 599, 601, 603,
                        615, 623, 628, 631, 639, 646, 654, 656, 658, 662, 674, 686, 698, 709, 724, 733, 735, 737, 746, 753, 761, 763, 765, 774,
                        783, 788, 791, 799, 806, 814, 816, 818, 822, 825, 826
                       };
}

char* TableLayoutParser::init__tableLayout_trans_targs_0 () {
    return new byte[] {1, 2, 36, 7, 4, 11, 62, 42, 104, 1, 58, 58, 58, 0, 4, 3, 4, 3, 5, 2, 6, 7, 4, 11, 4, 104, 5, 27, 27, 27,
                       0, 5, 2, 6, 7, 4, 11, 4, 104, 5, 27, 27, 27, 0, 6, 2, 7, 4, 11, 4, 104, 6, 0, 8, 0, 9, 0, 10, 2, 4, 11, 4, 10, 19, 19,
                       19, 0, 10, 2, 4, 11, 4, 10, 0, 11, 13, 4, 11, 12, 13, 4, 12, 15, 16, 0, 14, 4, 18, 15, 14, 14, 0, 0, 4, 0, 14, 14, 15,
                       16, 0, 14, 4, 18, 15, 14, 18, 17, 18, 17, 18, 4, 18, 0, 10, 2, 20, 4, 11, 4, 10, 19, 19, 19, 0, 20, 21, 23, 26, 21, 21,
                       20, 21, 21, 21, 0, 10, 21, 2, 22, 21, 4, 11, 21, 4, 10, 21, 21, 21, 0, 21, 23, 26, 21, 21, 21, 21, 21, 0, 25, 24, 25,
                       24, 10, 2, 22, 4, 11, 4, 10, 0, 21, 21, 21, 21, 21, 21, 0, 28, 2, 6, 7, 29, 4, 11, 4, 104, 28, 27, 27, 27, 0, 28, 2, 6,
                       7, 29, 4, 11, 4, 104, 28, 27, 27, 27, 0, 29, 30, 32, 35, 30, 30, 29, 30, 30, 30, 0, 5, 30, 2, 6, 31, 7, 30, 4, 11, 30,
                       4, 104, 5, 30, 30, 30, 0, 30, 32, 35, 30, 30, 30, 30, 30, 0, 34, 33, 34, 33, 5, 2, 6, 31, 7, 4, 11, 4, 104, 5, 0, 30,
                       30, 30, 30, 30, 30, 0, 36, 36, 37, 37, 37, 0, 38, 2, 7, 39, 4, 11, 4, 42, 104, 38, 37, 37, 37, 0, 38, 2, 7, 39, 4, 11,
                       4, 42, 104, 38, 37, 37, 37, 0, 39, 40, 54, 57, 40, 40, 39, 40, 40, 40, 0, 41, 40, 2, 53, 7, 40, 4, 11, 40, 4, 42, 104,
                       41, 40, 40, 40, 0, 41, 2, 7, 4, 11, 4, 42, 104, 41, 37, 37, 37, 0, 43, 2, 7, 4, 11, 4, 42, 104, 43, 44, 44, 44, 0, 43,
                       2, 7, 4, 11, 4, 42, 104, 43, 44, 44, 44, 0, 45, 2, 7, 46, 4, 11, 4, 42, 104, 45, 44, 44, 44, 0, 45, 2, 7, 46, 4, 11, 4,
                       42, 104, 45, 44, 44, 44, 0, 46, 47, 49, 52, 47, 47, 46, 47, 47, 47, 0, 43, 47, 2, 48, 7, 47, 4, 11, 47, 4, 42, 104, 43,
                       47, 47, 47, 0, 47, 49, 52, 47, 47, 47, 47, 47, 0, 51, 50, 51, 50, 43, 2, 48, 7, 4, 11, 4, 42, 104, 43, 0, 47, 47, 47,
                       47, 47, 47, 0, 40, 54, 57, 40, 40, 40, 40, 40, 0, 56, 55, 56, 55, 41, 2, 53, 7, 4, 11, 4, 42, 104, 41, 0, 40, 40, 40,
                       40, 40, 40, 0, 59, 2, 36, 7, 60, 4, 11, 4, 42, 104, 59, 58, 58, 58, 0, 59, 2, 36, 7, 60, 4, 11, 4, 42, 104, 59, 58, 58,
                       58, 0, 60, 61, 64, 67, 61, 61, 60, 61, 61, 61, 0, 62, 61, 2, 36, 63, 7, 61, 4, 11, 61, 4, 42, 104, 62, 61, 61, 61, 0,
                       62, 2, 36, 7, 4, 11, 4, 42, 104, 62, 58, 58, 58, 0, 61, 64, 67, 61, 61, 61, 61, 61, 0, 66, 65, 66, 65, 62, 2, 36, 63, 7,
                       4, 11, 4, 42, 104, 62, 0, 61, 61, 61, 61, 61, 61, 0, 68, 69, 105, 71, 73, 71, 68, 82, 82, 82, 0, 71, 70, 71, 70, 71, 69,
                       72, 105, 71, 73, 71, 71, 81, 81, 81, 0, 72, 69, 105, 71, 73, 71, 72, 0, 73, 75, 71, 73, 74, 75, 71, 74, 77, 78, 0, 76,
                       71, 80, 77, 76, 76, 0, 0, 71, 0, 76, 76, 77, 78, 0, 76, 71, 80, 77, 76, 80, 79, 80, 79, 80, 71, 80, 0, 81, 69, 72, 105,
                       71, 73, 71, 72, 81, 81, 81, 0, 83, 69, 105, 84, 71, 73, 71, 83, 82, 82, 82, 0, 83, 69, 105, 84, 71, 73, 71, 83, 82, 82,
                       82, 0, 84, 85, 87, 90, 85, 85, 84, 85, 85, 85, 0, 68, 85, 69, 105, 86, 85, 71, 73, 85, 71, 68, 85, 85, 85, 0, 85, 87,
                       90, 85, 85, 85, 85, 85, 0, 89, 88, 89, 88, 68, 69, 105, 86, 71, 73, 71, 68, 0, 85, 85, 85, 85, 85, 85, 0, 91, 92, 94,
                       106, 96, 94, 91, 0, 94, 93, 94, 93, 95, 92, 91, 94, 106, 96, 94, 95, 0, 95, 92, 91, 94, 106, 96, 94, 95, 0, 96, 98, 94,
                       96, 97, 98, 94, 97, 100, 101, 0, 99, 94, 103, 100, 99, 99, 0, 0, 94, 0, 99, 99, 100, 101, 0, 99, 94, 103, 100, 99, 103,
                       102, 103, 102, 103, 94, 103, 0, 104, 104, 0, 0, 0, 0
                      };
}

short* TableLayoutParser::init__tableLayout_trans_actions_0 () {
    return new short[] {0, 0, 0, 0, 31, 45, 0, 0, 29, 0, 1, 1, 1, 0, 53, 1, 25, 0, 39, 39, 206, 39, 203, 209, 197, 200, 39,
                        194, 194, 194, 0, 0, 0, 35, 0, 31, 45, 27, 29, 0, 1, 1, 1, 0, 0, 0, 0, 31, 45, 27, 29, 0, 0, 0, 0, 0, 0, 15, 15, 155,
                        158, 152, 15, 149, 149, 149, 0, 0, 0, 31, 45, 27, 0, 0, 1, 246, 242, 1, 1, 77, 71, 0, 1, 0, 0, 191, 23, 27, 1, 1, 21, 0,
                        0, 188, 0, 21, 0, 50, 0, 0, 191, 188, 27, 50, 1, 53, 1, 25, 0, 0, 23, 0, 0, 65, 65, 3, 302, 306, 298, 65, 0, 0, 0, 0, 0,
                        1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 89, 0, 89, 5, 0, 398, 402, 0, 394, 89, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 47, 1, 5, 0,
                        17, 17, 0, 164, 167, 161, 17, 0, 0, 0, 0, 0, 0, 0, 0, 68, 68, 322, 68, 3, 318, 326, 310, 314, 68, 0, 0, 0, 0, 0, 0, 35,
                        0, 0, 31, 45, 27, 29, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 92, 0, 92, 418, 5, 92, 0, 414, 422, 0, 406, 410,
                        92, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 47, 1, 5, 0, 19, 19, 179, 0, 19, 176, 182, 170, 173, 19, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 1, 1, 1, 0, 59, 59, 59, 3, 274, 278, 266, 59, 270, 59, 0, 0, 0, 0, 0, 0, 0, 0, 31, 45, 27, 0, 29, 0, 1, 1, 1,
                        0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 83, 0, 83, 5, 83, 0, 370, 374, 0, 362, 83, 366, 83, 0, 0, 0, 0, 0, 0, 0, 31, 45, 27,
                        0, 29, 0, 1, 1, 1, 0, 11, 11, 11, 131, 134, 125, 11, 128, 11, 122, 122, 122, 0, 0, 0, 0, 31, 45, 27, 0, 29, 0, 1, 1, 1,
                        0, 62, 62, 62, 3, 290, 294, 282, 62, 286, 62, 0, 0, 0, 0, 0, 0, 0, 0, 31, 45, 27, 0, 29, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1,
                        1, 0, 1, 1, 1, 0, 86, 0, 86, 5, 86, 0, 386, 390, 0, 378, 86, 382, 86, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 47, 1, 5,
                        0, 13, 13, 0, 13, 143, 146, 137, 13, 140, 13, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 47, 1, 5, 0, 9, 9, 0,
                        9, 116, 119, 110, 9, 113, 9, 0, 0, 0, 0, 0, 0, 0, 0, 56, 56, 56, 56, 3, 258, 262, 250, 56, 254, 56, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 31, 45, 27, 0, 29, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 80, 0, 80, 80, 5, 80, 0, 354, 358, 0, 346, 80,
                        350, 80, 0, 0, 0, 0, 0, 0, 0, 0, 31, 45, 27, 0, 29, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 47, 1, 5, 0, 7, 7, 7, 0,
                        7, 104, 107, 98, 7, 101, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 31, 45, 27, 0, 1, 1, 1, 0, 53, 1, 25, 0, 0, 41, 221, 224,
                        215, 227, 212, 0, 1, 1, 1, 0, 0, 0, 37, 31, 45, 27, 0, 0, 1, 246, 242, 1, 1, 77, 71, 0, 1, 0, 0, 191, 23, 27, 1, 1, 21,
                        0, 0, 188, 0, 21, 0, 50, 0, 0, 191, 188, 27, 50, 1, 53, 1, 25, 0, 0, 23, 0, 0, 0, 185, 450, 454, 446, 458, 442, 185, 0,
                        0, 0, 0, 74, 74, 338, 3, 334, 342, 330, 74, 0, 0, 0, 0, 0, 0, 37, 0, 31, 45, 27, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1,
                        1, 1, 0, 95, 0, 95, 434, 5, 0, 430, 438, 0, 426, 95, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 47, 1, 5, 0, 43, 43, 236, 0,
                        233, 239, 230, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 33, 45, 27, 0, 0, 53, 1, 25, 0, 41, 41, 221, 215, 218, 227, 212,
                        41, 0, 0, 0, 35, 31, 33, 45, 27, 0, 0, 1, 246, 242, 1, 1, 77, 71, 0, 1, 0, 0, 191, 23, 27, 1, 1, 21, 0, 0, 188, 0, 21,
                        0, 50, 0, 0, 191, 188, 27, 50, 1, 53, 1, 25, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0
                       };
}


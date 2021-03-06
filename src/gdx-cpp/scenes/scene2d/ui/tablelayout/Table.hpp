
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

#ifndef GDX_CPP_SCENES_SCENE2D_UI_TABLELAYOUT_TABLE_HPP_
#define GDX_CPP_SCENES_SCENE2D_UI_TABLELAYOUT_TABLE_HPP_

namespace gdx_cpp {
namespace scenes {
namespace scene2d {
namespace ui {
namespace tablelayout {

class Table {
public:
    Cell& add (const gdx_cpp::scenes::scene2d::Actor& actor);
    Cell& row ();
    void parse (const std::string& tableDescription);
    Cell& columnDefaults (int column);
    Cell& defaults ();
    void draw (const gdx_cpp::graphics::g2d::SpriteBatch& batch,float parentAlpha);
    void layout ();
    void invalidate ();
    float getPrefWidth ();
    float getPrefHeight ();
    void clear ();
    void drawDebug (const gdx_cpp::scenes::scene2d::Stage& stage);
    TableLayout& getTableLayout ();

protected:


private:
    void drawDebug (std::list<Actor>& actors,const gdx_cpp::graphics::g2d::SpriteBatch& batch);
    TableLayout layout;
};

} // namespace gdx_cpp
} // namespace scenes
} // namespace scene2d
} // namespace ui
} // namespace tablelayout

#endif // GDX_CPP_SCENES_SCENE2D_UI_TABLELAYOUT_TABLE_HPP_

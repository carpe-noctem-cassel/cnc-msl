/*
 * RobotVisualization.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Stefan Jakob
 */

#include <tools/basestation/RobotVisualization/RobotVisualization.h>

#include <vtkCallbackCommand.h>
#include <vtkSmartPointer.h>
#include <vtkLineSource.h>
#include <vtkSphereSource.h>
#include <vtkProperty.h>
#include <vtkProperty2D.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkTextSource.h>
#include <vtkCylinderSource.h>
#include <vtkVectorText.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkInteractorStyleSwitch.h>
#include <vtkInteractorStyleTerrain.h>
#include <vtkOBJReader.h>
#include <vtkTriangleStrip.h>
#include <vtkCellArray.h>
#include <vtkDataSetMapper.h>
#include <vtkFloatArray.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkTextWidget.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkViewport.h>
#include <vtkPointWidget.h>
#include <vtkPolygon.h>
#include <vtkPNGReader.h>
#include <vtkImageCanvasSource2D.h>
#include <vtkImageData.h>
#include <vtkImageMapper.h>
#include <vtkPropPicker.h>
#include <vtkObjectFactory.h>
#include <vtkPlaneSource.h>
#include <vtkPropCollection.h>
#include <vtkDelaunay2D.h>
#include <vtkLookupTable.h>
#include <vtkMath.h>
#include <vtkPointData.h>
#include <vtkCubeSource.h>
#include <vtkPyramid.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkRegularPolygonSource.h>
#include <vtkTetra.h>
#include <vtkLineWidget.h>
#include <vtkFollower.h>
#include <vtkDiskSource.h>
#include <vtkArcSource.h>

#include "RobotInfo.h"
#include "FieldWidget3D.h"

struct Color{
    static std::map<std::string, std::array<double,3>> create_map()
        {
      std::map<std::string, std::array<double,3>> m;
          m["default"] = {0.0, 0.0, 0.0};
          m["mops"] = {1.0, 0.0, 0.0};
          m["hairy"] = {1.0, 1.0, 0.0};
          m["nase"] = {0.0, 1.0, 0.0};
          m["savvy"] = {0.0, 1.0, 1.0};
          m["myo"] = {0.0, 0.0, 1.0};
          m["brain"] = {1.0, 0.0, 1.0};
          m["path"] = {1.0, 1.0, 1.0};
          return m;
        }
    static std::map<std::string, std::array<double,3>> map;

    static std::array<double,3>& getColor(int id)
    {
      if (id == 1)
        return map["mops"];
      else if (id == 8)
        return map["hairy"];
      else if (id == 9)
        return map["nase"];
      else if( id == 10)
        return map["savvy"];
      else if( id == 11)
        return map["myo"];
      else if( id == 100)
        return map["brain"];

      return map["default"];
    }
};

std::map<std::string, std::array<double,3>> Color::map =  Color::create_map();

RobotVisualization::RobotVisualization(RobotInfo* robot, FieldWidget3D* field) : robot(robot), field(field)
{
	id = 0;
	senderId = 0;
	visible = false;
}

RobotVisualization::~RobotVisualization()
{
	// nothing to do here
}

vtkSmartPointer<vtkActor> RobotVisualization::getBottom()
{
	return bottom;
}

void RobotVisualization::setBottom(vtkSmartPointer<vtkActor> bottom)
{
	this->bottom = bottom;
}

void RobotVisualization::setNameActor(vtkSmartPointer<vtkActor> nameActor)
{
	this->nameActor = nameActor;
}

vtkSmartPointer<vtkActor> RobotVisualization::getNameActor()
{
	return this->nameActor;
}

vtkSmartPointer<vtkActor> RobotVisualization::getTop()
{
	return top;
}

void RobotVisualization::setTop(vtkSmartPointer<vtkActor> top)
{
	this->top = top;
}
int RobotVisualization::getId()
{
	return id;
}

void RobotVisualization::setId(int id)
{
	this->id = id;
}

 std::string RobotVisualization::getName()
{
	return name;
}

void RobotVisualization::setName(std::string name)
{
	this->name = name;
}

int RobotVisualization::getSenderId()
{
	return senderId;
}

void RobotVisualization::setSenderId(int senderId)
{
	this->senderId = senderId;
}

vtkActor* RobotVisualization::getBall()
{
	return ball;
}

void RobotVisualization::setBall(vtkActor* ball)
{
	this->ball = ball;
}

vtkSmartPointer<vtkLineSource> RobotVisualization::getBallVelocity()
{
	return ballVelocity;
}

void RobotVisualization::setBallVelocity(vtkSmartPointer<vtkLineSource> ballVelocity)
{
	this->ballVelocity = ballVelocity;
}

vtkSmartPointer<vtkActor> RobotVisualization::getBallVelocityActor()
{
	return ballVelocityActor;
}

void RobotVisualization::setBallVelocityActor(vtkSmartPointer<vtkActor> ballVelocityActor)
{
	this->ballVelocityActor = ballVelocityActor;
}

vtkSmartPointer<vtkActor> RobotVisualization::getSharedBall()
{
	return sharedBall;
}

void RobotVisualization::setSharedBall(vtkSmartPointer<vtkActor> sharedBall)
{
	this->sharedBall = sharedBall;
}

void RobotVisualization::remove(vtkRenderer *renderer)
{
        this->visible = false;

        this->top->SetVisibility(false);
        this->bottom->SetVisibility(false);
        this->nameActor->SetVisibility(false);
        this->ball->SetVisibility(false);
        this->ballVelocityActor->SetVisibility(false);
        this->sharedBall->SetVisibility(false);

        for (vtkSmartPointer<vtkActor> actor : obstacles)
        {
                actor->SetVisibility(false);
        }

        for (vtkSmartPointer<vtkActor> actor : pathLines)
        {
                if (actor != nullptr)
                {
                        renderer->RemoveActor(actor);
                }
        }
        pathLines.clear();

        // path planner corridor check
        this->corridorLine1->actor->SetVisibility(false);
        this->corridorLine2->actor->SetVisibility(false);
        this->corridorLine3->actor->SetVisibility(false);
        this->corridorLine4->actor->SetVisibility(false);

        // voronoi net
        for (int i=0; i < this->netLines.size(); ++i)
        {
                this->netLines.at(i)->actor->SetVisibility(false);
        }

        for (vtkSmartPointer<vtkActor> actor : sitePoints)
        {
                if (actor != nullptr)
                {
                        renderer->RemoveActor(actor);
                }
        }
        sitePoints.clear();

        // debug points
        for (vtkSmartPointer<vtkActor> actor : this->debugPoints)
        {
                if (actor != nullptr)
                {
                        renderer->RemoveActor(actor);
                }
        }
        debugPoints.clear();

        // pass msg
        this->passActor->SetVisibility(false);
        this->passPointActor->SetVisibility(false);
}

void RobotVisualization::init(vtkRenderer *renderer, int id)
{
        auto color = Color::getColor(this->robot->getId());

        this->setId(id);
        this->setName(std::to_string(id));
        this->setBall(nullptr);

        vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

        float p0[3] = {0.26, 0, 0};
        float p1[3] = {-0.26, 0.26, 0};
        float p2[3] = {-0.26, -0.26, 0};
        float p3[3] = {0.0, 0.0, 0.4};

        points->InsertNextPoint(p0);
        points->InsertNextPoint(p1);
        points->InsertNextPoint(p2);
        points->InsertNextPoint(p3);

        vtkSmartPointer<vtkTetra> tetra = vtkSmartPointer<vtkTetra>::New();
        tetra->GetPointIds()->SetId(0, 0);
        tetra->GetPointIds()->SetId(1, 1);
        tetra->GetPointIds()->SetId(2, 2);
        tetra->GetPointIds()->SetId(3, 3);

        vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
        cells->InsertNextCell(tetra);

        vtkSmartPointer<vtkUnstructuredGrid> ug = vtkSmartPointer<vtkUnstructuredGrid>::New();
        ug->SetPoints(points);
        ug->InsertNextCell(tetra->GetCellType(), tetra->GetPointIds());

        vtkSmartPointer<vtkDataSetMapper> teamTopMapper = vtkSmartPointer<vtkDataSetMapper>::New();
        teamTopMapper->SetInput(ug);

        vtkSmartPointer<vtkCubeSource> cubeSrc = vtkSmartPointer<vtkCubeSource>::New();
        cubeSrc->SetXLength(0.52);
        cubeSrc->SetYLength(0.52);
        cubeSrc->SetZLength(0.4);

        vtkSmartPointer<vtkPolyDataMapper> teamBottomMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        teamBottomMapper->SetInputConnection(cubeSrc->GetOutputPort());

        vtkSmartPointer<vtkActor> teamBottom = vtkSmartPointer<vtkActor>::New();
        teamBottom->SetMapper(teamBottomMapper);
        teamBottom->SetPosition(0, 0, 0.2);
        teamBottom->GetProperty()->SetColor(1, 1, 1);
        teamBottom->GetProperty()->SetDiffuse(0.4);
        teamBottom->GetProperty()->SetAmbient(0.8);
        renderer->AddActor(teamBottom);

        vtkSmartPointer<vtkActor> teamTop = vtkSmartPointer<vtkActor>::New();
        teamTop->SetMapper(teamTopMapper);
        teamTop->SetPosition(0, 0, 0.4);
        auto c = Color::getColor(this->robot->getId());
        teamTop->GetProperty()->SetColor(c[0], c[1], c[2]);
        teamTop->GetProperty()->SetDiffuse(0.4);
        teamTop->GetProperty()->SetAmbient(0.8);
        renderer->AddActor(teamTop);

        // Name Actor
        // Create text
        vtkSmartPointer<vtkVectorText> textSource = vtkSmartPointer<vtkVectorText>::New();
        textSource->SetText((this->name).c_str());
        textSource->Update();

        // Create a mapper and actor
        vtkSmartPointer<vtkPolyDataMapper> nameMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        nameMapper->SetInputConnection(textSource->GetOutputPort());

        vtkSmartPointer<vtkFollower> nameActor = vtkSmartPointer<vtkFollower>::New();
        nameActor->SetMapper(nameMapper);
        nameActor->GetProperty()->SetColor(1.0, 0.0, 0.0);
        nameActor->GetProperty()->SetDiffuse(0.4);
        nameActor->GetProperty()->SetAmbient(0.8);
        nameActor->SetPosition(0, 0, 1);
        nameActor->SetScale(0.5);

        renderer->AddActor(nameActor);
        nameActor->SetCamera( renderer->GetActiveCamera() );

        this->top = teamTop;
        this->bottom = teamBottom;
        this->nameActor = nameActor;

        this->top->SetVisibility(false);
        this->bottom->SetVisibility(false);
        this->nameActor->SetVisibility(false);

        // ball
        vtkSmartPointer<vtkSphereSource> sphereSrc = vtkSmartPointer<vtkSphereSource>::New();
        sphereSrc->SetRadius(field->_BALL_DIAMETER / 2);
        vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        sphereMapper->SetInput(sphereSrc->GetOutput());
        this->ball = vtkSmartPointer<vtkActor>::New();
        this->ball->SetMapper(sphereMapper);
        this->ball->GetProperty()->SetRepresentationToSurface();
        this->ball->GetProperty()->SetColor(255, 0, 0);
        this->ball->SetPosition(0, 0, this->field->_BALL_DIAMETER / 2);
        renderer->AddActor(this->ball);

        this->ballVelocity = vtkSmartPointer<vtkLineSource>::New();
        this->ballVelocity->SetPoint1(0, 0, 0);
        this->ballVelocity->SetPoint2(0, 0, 0);

        vtkSmartPointer<vtkPolyDataMapper> velocityMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        velocityMapper->SetInput(this->ballVelocity->GetOutput());
        this->ballVelocityActor = vtkSmartPointer<vtkActor>::New();
        this->ballVelocityActor->SetMapper(velocityMapper);
        this->ballVelocityActor->GetProperty()->SetLineWidth(this->field->_LINE_THICKNESS / 2);
        this->ballVelocityActor->GetProperty()->SetColor(1, 0, 0);
        this->ballVelocityActor->GetProperty()->SetDiffuse(0.4);
        this->ballVelocityActor->GetProperty()->SetAmbient(0.8);

        renderer->AddActor(this->ballVelocityActor);
        this->ball->SetVisibility(false);
        this->ballVelocityActor->SetVisibility(false);

        // shared ball
        vtkSmartPointer<vtkRegularPolygonSource> polygonSource = vtkSmartPointer<vtkRegularPolygonSource>::New();
        polygonSource->SetNumberOfSides(50);
        polygonSource->SetRadius(this->field->_BALL_DIAMETER * 1.5);
        polygonSource->Update();

        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(polygonSource->GetOutputPort());
        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        actor->GetProperty()->SetColor(0, 0, 0.5);
        actor->GetProperty()->SetDiffuse(0.4);
        actor->GetProperty()->SetAmbient(0.8);

        this->sharedBall = actor;
        renderer->AddActor(actor);
        this->sharedBall->SetVisibility(false);

        // corridor
        this->corridorLine1 = FieldWidget3D::createDashedLine(0, 0, 0.01, 0, 0, 0.01, 3, this->getDashedPattern(), color);
        this->corridorLine2 = FieldWidget3D::createDashedLine(0, 0, 0.01, 0, 0, 0.01, 3, this->getDashedPattern(), color);
        this->corridorLine3 = FieldWidget3D::createDashedLine(0, 0, 0.01, 0, 0, 0.01, 3, this->getDashedPattern(), color);
        this->corridorLine4 = FieldWidget3D::createDashedLine(0, 0, 0.01, 0, 0, 0.01, 3, this->getDashedPattern(), color);

        this->corridorLine1->actor->SetVisibility(false);
        this->corridorLine2->actor->SetVisibility(false);
        this->corridorLine3->actor->SetVisibility(false);
        this->corridorLine4->actor->SetVisibility(false);

        renderer->AddActor(this->corridorLine1->actor);
        renderer->AddActor(this->corridorLine2->actor);
        renderer->AddActor(this->corridorLine3->actor);
        renderer->AddActor(this->corridorLine4->actor);

        // pass msg
        vtkSmartPointer<vtkLineSource> line = vtkSmartPointer<vtkLineSource>::New();
        vtkSmartPointer<vtkPolyDataMapper> lineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        vtkSmartPointer<vtkActor> lineActor = vtkSmartPointer<vtkActor>::New();
        line->SetPoint1(0, 0, 0);
        line->SetPoint2(0, 0, 0);
        lineMapper->SetInputConnection(line->GetOutputPort());
        lineActor->SetMapper(lineMapper);
        lineActor->GetProperty()->SetLineWidth(3);
        lineActor->GetProperty()->SetColor(c[0], c[1], c[2]);
        lineActor->GetProperty()->SetPointSize(1);

        this->pass = line;
        this->passActor = lineActor;
        this->passActor->SetVisibility(false);
        this->passPointActor = FieldWidget3D::createDot(0, 0, 0.22, c);
        this->passPointActor->SetVisibility(false);

        renderer->AddActor(this->passActor);
        renderer->AddActor(this->passPointActor);
}

void RobotVisualization::updatePosition(vtkRenderer *renderer)
{
        auto pos = this->field->transformToGuiCoords(robot->getSharedWorldInfo()->odom.position.x, robot->getSharedWorldInfo()->odom.position.y);

        this->top->SetPosition(pos.first, pos.second, 0.4);
        this->bottom->SetPosition(pos.first, pos.second, 0.2);
        this->nameActor->SetPosition(pos.first, pos.second, 1);

        this->top->SetOrientation(0, 0, robot->getSharedWorldInfo()->odom.position.angle * (180.0 / (double)M_PI) + 90);
        this->bottom->SetOrientation(0, 0, robot->getSharedWorldInfo()->odom.position.angle * (180.0 / (double)M_PI) + 90);

        this->top->SetVisibility(true);
        this->bottom->SetVisibility(true);
        this->nameActor->SetVisibility(true);
}


void RobotVisualization::updateBall(vtkRenderer *renderer)
{
        if (robot->getSharedWorldInfo()->ball.confidence <= 0)
        {
                this->ball->SetVisibility(false);
                this->ballVelocityActor->SetVisibility(false);
        }

        auto pos = this->field->transformToGuiCoords(robot->getSharedWorldInfo()->ball.point.x, robot->getSharedWorldInfo()->ball.point.y);

        this->ball->SetPosition(pos.first, pos.second, robot->getSharedWorldInfo()->ball.point.z / 1000);
        this->ballVelocity->SetPoint1(pos.first, pos.second, robot->getSharedWorldInfo()->ball.point.z / 1000);
        auto ballVelTrans = this->field->transformToGuiCoords(robot->getSharedWorldInfo()->ball.velocity.vx, robot->getSharedWorldInfo()->ball.velocity.vy);
        this->ballVelocity->SetPoint2(pos.first + ballVelTrans.first, pos.second + ballVelTrans.second,
                                            robot->getSharedWorldInfo()->ball.point.z / 1000 + robot->getSharedWorldInfo()->ball.velocity.vz / 1000);

        this->ball->SetVisibility(true);
        this->ballVelocityActor->SetVisibility(true);
}


void RobotVisualization::updateSharedBall(vtkRenderer *renderer)
{
        if (robot->getSharedWorldInfo()->sharedBall.confidence <= 0)
        {
                this->sharedBall->SetVisibility(false);
                return;
        }

        auto pos = this->field->transformToGuiCoords(robot->getSharedWorldInfo()->sharedBall.point.x, robot->getSharedWorldInfo()->sharedBall.point.y);
        this->sharedBall->SetPosition(pos.first, pos.second, robot->getSharedWorldInfo()->sharedBall.point.z / 1000 + 0.01);
        this->sharedBall->SetVisibility(true);
}

void RobotVisualization::updateOpponents(vtkRenderer *renderer)
{
        bool alreadyIn = false;
        int obstacleCount = 0;

        for (auto x : robot->getSharedWorldInfo()->obstacles)
        {
                auto pos = this->field->transformToGuiCoords(x.x, x.y);
                for (auto member : *this->field->getRobots())
                {
                        auto mb = member->getVisualization()->getBottom();
                        if (mb == nullptr)
                          continue;

                        if (abs(mb->GetPosition()[0] - pos.first) < 0.25
                                        && abs(mb->GetPosition()[1] - pos.second) < 0.25)
                        {
                                alreadyIn = true;
                        }
                }

                if (!alreadyIn)
                {
                        if (obstacleCount < this->obstacles.size())
                        {
                                this->obstacles.at(obstacleCount)->SetPosition(pos.first, pos.second, 0);
                                this->obstacles.at(obstacleCount)->SetVisibility(true);
                        }
                        else
                        {
                                drawOpponent(renderer, pos.first, pos.second, 0);
                        }
                        obstacleCount++;
                }
                alreadyIn = false;
        }

        if (obstacleCount < this->obstacles.size())
        {
                for (int i = obstacleCount; i < this->obstacles.size(); ++i)
                {
                          this->obstacles.at(i)->SetVisibility(false);
                }
        }
}

void RobotVisualization::drawOpponent(vtkRenderer *renderer, double x, double y, double z)
{
        vtkSmartPointer<vtkCubeSource> cubeSrc = vtkSmartPointer<vtkCubeSource>::New();
        cubeSrc->SetXLength(0.52);
        cubeSrc->SetYLength(0.52);
        cubeSrc->SetZLength(0.8);

        vtkSmartPointer<vtkPolyDataMapper> obstacleBottomMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        obstacleBottomMapper->SetInputConnection(cubeSrc->GetOutputPort());

        vtkSmartPointer<vtkActor> obstacleBottom = vtkSmartPointer<vtkActor>::New();
        obstacleBottom->SetMapper(obstacleBottomMapper);
        obstacleBottom->SetPosition(x, y, z + 0.2);
        obstacleBottom->GetProperty()->SetColor(0, 0, 0);
        obstacleBottom->GetProperty()->SetDiffuse(0.4);
        obstacleBottom->GetProperty()->SetAmbient(0.8);
        renderer->AddActor(obstacleBottom);

        obstacles.push_back(obstacleBottom);
}

void RobotVisualization::updatePathPlannerDebug(vtkRenderer *renderer, bool show)
{
        // Check last message
        boost::shared_ptr<msl_msgs::PathPlanner> ppi;
        bool timeout = false;
        {
              lock_guard<mutex> lock(this->field->pathMutex);
              ppi = this->robot->getPathPlannerInfo();
              timeout = this->robot->isPathPlannerMsgTimeout();

              if (false == ppi)
                      return;
        }

        // Remove old stuff
        for (vtkSmartPointer<vtkActor> actor : pathLines)
        {
                if (actor != nullptr)
                {
                        renderer->RemoveActor(actor);
                }
        }
        pathLines.clear();

        if (false == show || timeout)
          return;

        // Draw new
        for (int i = 1; i < ppi->pathPoints.size(); i++)
        {
                pair<double, double> point1 = this->field->transformToGuiCoords(ppi->pathPoints.at(i - 1).x, ppi->pathPoints.at(i - 1).y);
                pair<double, double> point2 = this->field->transformToGuiCoords(ppi->pathPoints.at(i).x, ppi->pathPoints.at(i).y);

                vtkSmartPointer<vtkActor> actor = FieldWidget3D::createLine(point1.first, point1.second, 0.01,
                                                                            point2.first, point2.second, 0.01,
                                                                            3, Color::getColor(this->robot->getId()));
                pathLines.push_back(actor);
                renderer->AddActor(actor);
        }
}

void RobotVisualization::updateCorridorDebug(vtkRenderer *renderer, bool show)
{
        // Check last message
        boost::shared_ptr<msl_msgs::CorridorCheck> cc;
        bool timeout = false;
        {
                lock_guard<mutex> lock(this->field->corridorMutex);
                cc = this->robot->getCorridorCheckInfo();
                timeout = this->robot->isCorridorCheckMsgTimeout();

                if (false == cc)
                        return;
        }

        if (false == show || timeout)
        {
          this->corridorLine1->actor->SetVisibility(false);
          this->corridorLine2->actor->SetVisibility(false);
          this->corridorLine3->actor->SetVisibility(false);
          this->corridorLine4->actor->SetVisibility(false);
          return;
        }

        pair<double, double> point0 = this->field->transformToGuiCoords(cc->corridorPoints.at(0).x, cc->corridorPoints.at(0).y);
        pair<double, double> point1 = this->field->transformToGuiCoords(cc->corridorPoints.at(1).x, cc->corridorPoints.at(1).y);
        pair<double, double> point2 = this->field->transformToGuiCoords(cc->corridorPoints.at(2).x, cc->corridorPoints.at(2).y);
        pair<double, double> point3 = this->field->transformToGuiCoords(cc->corridorPoints.at(3).x, cc->corridorPoints.at(3).y);

        // Draw new
        this->corridorLine1->source->SetPoint1(point0.first, point0.second, 0.01);
        this->corridorLine1->source->SetPoint2(point1.first, point1.second, 0.01);

        this->corridorLine2->source->SetPoint1(point1.first, point1.second, 0.01);
        this->corridorLine2->source->SetPoint2(point2.first, point2.second, 0.01);

        this->corridorLine3->source->SetPoint1(point2.first, point2.second, 0.01);
        this->corridorLine3->source->SetPoint2(point3.first, point3.second, 0.01);

        this->corridorLine4->source->SetPoint1(point3.first, point3.second, 0.01);
        this->corridorLine4->source->SetPoint2(point0.first, point0.second, 0.01);

        this->corridorLine1->actor->SetVisibility(true);
        this->corridorLine2->actor->SetVisibility(true);
        this->corridorLine3->actor->SetVisibility(true);
        this->corridorLine4->actor->SetVisibility(true);
}

void RobotVisualization::updateVoronoiNetDebug(vtkRenderer *renderer, bool showVoronoi, bool showSitePoints)
{

        if(false == showVoronoi && false == showSitePoints)
        {
                return;
        }

        // Check last message
        boost::shared_ptr<msl_msgs::VoronoiNetInfo> vni;
        bool timeout = false;
        {
                lock_guard<mutex> lock(this->field->voronoiMutex);
                vni = this->robot->getVoronoiNetInfo();
                timeout = this->robot->isVoronoiNetMsgTimeout();

                if (false == vni)
                        return;
        }

        // Remove old stuff
        for (vtkSmartPointer<vtkActor> actor : sitePoints)
        {
                if (actor != nullptr)
                {
                        renderer->RemoveActor(actor);
                }
        }
        sitePoints.clear();

        if (false == showVoronoi || timeout)
        {
                for (int i=0; i < this->netLines.size(); ++i)
                {
                        this->netLines.at(i)->actor->SetVisibility(false);
                }
        }

        if ((false == showVoronoi && false == showSitePoints) || timeout)
                return;

        int used = 0;
        vtkSmartPointer<vtkActor> actor;
        auto color = Color::getColor(this->robot->getId());

        // Draw voronoi net
        if(showVoronoi)
        {
                for (int i = 1; i < vni->linePoints.size(); i += 2)
                {
                        pair<double, double> point1 = this->field->transformToGuiCoords(vni->linePoints.at(i - 1).x, vni->linePoints.at(i - 1).y);
                        pair<double, double> point2 = this->field->transformToGuiCoords(vni->linePoints.at(i).x, vni->linePoints.at(i).y);

                        if (used >= this->netLines.size())
                        {
                                auto line = FieldWidget3D::createDashedLine(point1.first, point1.second, 0.01,
                                                                            point2.first, point2.second, 0.01,
                                                                            3, this->getDashedPattern(), color);

                                renderer->AddActor(line->actor);
                                this->netLines.push_back(line);
                        }
                        else
                        {
                                auto line = this->netLines.at(used);
                                line->actor->SetVisibility(true);
                                line->source->SetPoint1(point1.first, point1.second, 0.01);
                                line->source->SetPoint2(point2.first, point2.second, 0.01);
                        }
                        ++used;
                }

                if (used < this->netLines.size())
                {
                        for (int i=used; i < this->netLines.size(); ++i)
                        {
                                this->netLines.at(i)->actor->SetVisibility(false);
                        }
                }
        }

        // Draw side points
        if(showSitePoints)
        {
                for (vtkSmartPointer<vtkActor> actor : sitePoints)
                {
                        if (actor != nullptr)
                        {
                                renderer->RemoveActor(actor);
                        }
                }
                sitePoints.clear();

                for (int i = 0; i < vni->sites.size(); i++)
                {
                        pair<double, double> point = this->field->transformToGuiCoords(vni->sites.at(i).x, vni->sites.at(i).y);

                        vtkSmartPointer<vtkActor> actor = FieldWidget3D::createDot(point.first, point.second, 0.3,
                                                                                   Color::getColor(this->robot->getId()));
                        sitePoints.push_back(actor);
                        renderer->AddActor(actor);
                }
        }
}


void RobotVisualization::updateDebugPoints(vtkRenderer *renderer, bool showDebugPoints)
{
        // Check last message
        boost::shared_ptr<msl_helper_msgs::DebugMsg> debugMsg;
        bool timeout = false;
        {
                lock_guard<mutex> lock(this->field->debugMutex);
                debugMsg = this->robot->getDebugMsg();
                timeout = this->robot->isDebugMsgTimeout();
        }

        // Remove old objects if show path is disabled
        for (vtkSmartPointer<vtkActor> actor : this->debugPoints)
        {
                if (actor != nullptr)
                {
                        renderer->RemoveActor(actor);
                }
        }
        debugPoints.clear();

        // Return if nothing should be drawn
        if (false == showDebugPoints || false == debugMsg || timeout)
        {
                return;
        }

        // Draw debug points
        for (int i = 0; i < debugMsg->points.size(); i++)
        {
                auto pointDbg = debugMsg->points.at(i);
                std::array<double,3> color = {pointDbg.red / 255.0, pointDbg.green / 255.0, pointDbg.blue / 255.0};
                pair<double, double> point = this->field->transformToGuiCoords(pointDbg.point.x, pointDbg.point.y);

                vtkSmartPointer<vtkActor> actor = FieldWidget3D::createDot(point.first, point.second, 0.3, color);
                debugPoints.push_back(actor);
                renderer->AddActor(actor);
        }
}

void RobotVisualization::updatePassMsg(vtkRenderer *renderer)
{
        // Check last message
        boost::shared_ptr<msl_helper_msgs::PassMsg> passMsg;
        bool timeout = false;
        {
                lock_guard<mutex> lock(this->field->passMutex);
                passMsg = this->robot->getPassMsg();
                timeout = this->robot->isPassMsgTimeout();
        }

        // Return if nothing should be drawn
        if (false == passMsg || timeout)
        {
                this->passActor->SetVisibility(false);
                this->passPointActor->SetVisibility(false);
                return;
        }

        // Draw debug points
        this->passActor->SetVisibility(true);
        this->passPointActor->SetVisibility(true);
        auto origin = this->field->transformToGuiCoords(passMsg->origin.x, passMsg->origin.y);
        auto dest = this->field->transformToGuiCoords(passMsg->destination.x, passMsg->destination.y);

        this->pass->SetPoint1(origin.first, origin.second, 0.01);
        this->pass->SetPoint2(dest.first, dest.second, 0.01);

        this->passPointActor->SetPosition(dest.first, dest.second, 0.01);
}

int RobotVisualization::getDashedPattern()
{
        return 0x66 << this->robot->getId();
}

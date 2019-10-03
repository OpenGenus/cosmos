/*
 * Analytical calculations for sphere-tetrahedron intersections.
 *
 * See here for it's mathematical description:
 * https://www.quora.com/What-are-some-equations-that-you-made-up/answer/Mahmut-Akku%C5%9F
 *
 *   - RedBlight
 *
 */

#include <cmath>
#include "LuVector.hpp"
using Vec3 = LUV::LuVector<3, double>;

// Returns the solid angle of sphere cap contended by a cone.
// Apex of the cone is center of the sphere.
double SolidAngleCap(double apexAngle)
{
    return 2.0 * LUV::pi * (1.0 - std::cos(apexAngle));
}

// Returns the solid angle of a spherical triangle.
// v1, v2, v3 are vertices of the triangle residing on a unit sphere.
double SolidAngleSphtri(const Vec3& v1, const Vec3& v2, const Vec3& v3)
{
    double ang0 = std::acos(LUV::Dot(v1, v2));
    double ang1 = std::acos(LUV::Dot(v2, v3));
    double ang2 = std::acos(LUV::Dot(v3, v1));
    double angSum = (ang0 + ang1 + ang2) / 2.0;
    return 4.0 * std::atan(std::sqrt(
                               std::tan(angSum / 2.0) *
                               std::tan((angSum - ang0) / 2.0) *
                               std::tan((angSum - ang1) / 2.0) *
                               std::tan((angSum - ang2) / 2.0)
                               ));
}

// Returns the volume of spherical cap.
double VolumeCap(double radius, double height)
{
    return radius * radius * height * LUV::pi * (2.0 / 3.0);
}

// Returns the volume of cone.
double VolumeCone(double radius, double height)
{
    return radius * radius * height * LUV::pi * (1.0 / 3.0);
}

// Returns the volume of tetrahedron given it's 4 vertices.
double VolumeTetrahedron(const Vec3& v1, const Vec3& v2, const Vec3& v3, const Vec3& v4)
{
    return std::abs(LUV::Dot(v1 - v4, LUV::Cross(v2 - v4, v3 - v4))) / 6.0;
}

// Returns the volume of triangular slice taken from a sphere.
double VolumeSphtri(const Vec3& v1, const Vec3& v2, const Vec3& v3, double radius)
{
    return SolidAngleSphtri(v1, v2, v3) * radius * radius * radius / 3.0;
}

/*
 * Observation tetrahedra (OT) are special tetrahedra constructed for analytical calculations.
 * OTs have right angles in many of their corners, and one of their vertices are the center of the sphere.
 * For this reason, their intersections with the sphere can be calculated analytically.
 * When 24 OTs contructed for each vertex, of each edge, of each face, of any arbitrary tetrahedron,
 * their combinations can be used to analytically calculate intersections of any arbitrary sphere and tetrahedron.
 *
 */
class ObservationTetrahedron
{
public:

    // Cartesian coordinates of vertices:
    Vec3 posR, posA, posB, posC;

    // Distances from posR:
    double lenA, lenB, lenC;

    // Direction of sphere-edge intersection points as radius increases:
    Vec3 prdA, prdB, prdC, prdD, prdE, prdF;

    // Some angles between lines:
    double angBAC, angERA, angFAE;

    // Max. solid angle contended by OT
    double solidAngleFull;

    // Constructor
    ObservationTetrahedron(const Vec3& vR, const Vec3& vA, const Vec3& vB, const Vec3& vC)
    {
        posR = vR;
        posA = vA;
        posB = vB;
        posC = vC;

        Vec3 AmR = vA - vR;
        Vec3 BmR = vB - vR;
        Vec3 CmR = vC - vR;
        Vec3 BmA = vB - vA;
        Vec3 CmA = vC - vA;
        Vec3 CmB = vC - vB;

        lenA = LUV::Length(AmR);
        lenB = LUV::Length(BmR);
        lenC = LUV::Length(CmR);

        prdA = AmR / lenA;
        prdB = BmR / lenB;
        prdC = CmR / lenC;
        prdD = BmA / LUV::Length(BmA);
        prdE = CmA / LUV::Length(CmA);
        prdF = CmB / LUV::Length(CmB);

        angBAC = std::acos(LUV::Dot(prdD, prdE));
        solidAngleFull = SolidAngleSphtri(prdA, prdB, prdC);
    }

    // Solid angle of the sphere subtended by OT as a function of sphere radius.
    double GetSolidAngle(double radius)
    {
        RecalculateForRadius(radius);

        if (radius >= lenC)
            return 0;

        else if (radius >= lenB)
            return SolidAngleSphtri(dirA, dirC, dirF) -
                   SolidAngleCap(angERA) * angFAE / (2.0 * LUV::pi);

        else if (radius >= lenA)
            return solidAngleFull -
                   SolidAngleCap(angERA) * angBAC / (2.0 * LUV::pi);

        return solidAngleFull;
    }

    // Surface area of the sphere subtended by OT as a function of sphere radius.
    double GetSurfaceArea(double radius)
    {
        return GetSolidAngle(radius) * radius * radius;
    }

    // Volume of OT-sphere intersection, as a function of sphere radius.
    double GetVolume(double radius)
    {
        RecalculateForRadius(radius);

        if (radius >= lenC)
            return VolumeTetrahedron(posR, posA, posB, posC);

        else if (radius >= lenB)
            return VolumeSphtri(dirA, dirC, dirF, radius) - (
                VolumeCap(radius, LUV::Length(prpA - posA)) -
                VolumeCone(prlE, lenA)
                ) * angFAE / (2.0 * LUV::pi) +
                   VolumeTetrahedron(posR, posA, posB, prpF);

        else if (radius >= lenA)
            return VolumeSphtri(dirA, dirB, dirC, radius) - (
                VolumeCap(radius, LUV::Length(prpA - posA)) -
                VolumeCone(prlE, lenA)
                ) * angBAC / (2.0 * LUV::pi);

        return VolumeSphtri(dirA, dirB, dirC, radius);
    }

private:

    // Angles of RBF triangle
    double angRBF, angBFR, angFRB;

    // Distance of sphere-edge intersections:
    double prlA, prlB, prlC, prlD, prlE, prlF;
    //R->A, R->B, R->C, A->B, A->C, B->C

    // Positions of sphere-edge intersections:
    Vec3 prpA, prpB, prpC, prpD, prpE, prpF;

    // Positions relative to posR:
    // All have the length = radius
    Vec3 vecA, vecB, vecC, vecD, vecE, vecF;

    // Directions from posR:
    Vec3 dirA, dirB, dirC, dirD, dirE, dirF;

    // OT vertices are not actually dependent on the radius of the sphere, only the center.
    // But some values need to be calculated for each radius.
    void RecalculateForRadius(double radius)
    {
        angRBF = std::acos(LUV::Dot(posR - posB, posC - posB));
        angBFR = std::asin(lenB * std::sin(angRBF) / radius);
        angFRB = LUV::pi - (angRBF + angBFR);

        prlA = radius;
        prlB = radius;
        prlC = radius;
        prlD = std::sqrt(radius * radius - lenA * lenA);
        prlE = prlD;
        prlF = lenB * std::sin(angFRB) / sin(angBFR);

        prpA = posR + prdA * prlA;
        prpB = posR + prdB * prlB;
        prpC = posR + prdC * prlC;
        prpD = posA + prdD * prlD;
        prpE = posA + prdE * prlE;
        prpF = posB + prdF * prlF;

        vecA = prpA - posR;
        vecB = prpB - posR;
        vecC = prpC - posR;
        vecD = prpD - posR;
        vecE = prpE - posR;
        vecF = prpF - posR;

        dirA = vecA / LUV::Length(vecA);
        dirB = vecB / LUV::Length(vecB);
        dirC = vecC / LUV::Length(vecC);
        dirD = vecD / LUV::Length(vecD);
        dirE = vecE / LUV::Length(vecE);
        dirF = vecF / LUV::Length(vecF);

        angERA = std::acos(LUV::Dot(dirE, dirA));
        Vec3 vecAF = prpF - posA;
        Vec3 vecAE = prpE - posA;
        angFAE = std::acos(LUV::Dot(vecAF, vecAE) / (LUV::Length(vecAF) * LUV::Length(vecAE)));
    }

};

// Main class for the intersection.
class SphereTetrahedronIntersection
{

public:

    // Constructor,
    // vecTetA..D are vertices of the tetrahedron.
    // vecSphCenter is the center of the sphere.
    SphereTetrahedronIntersection(const Vec3& vecTetA, const Vec3& vecTetB, const Vec3& vecTetC,
                                  const Vec3& vecTetD, const Vec3& vecSphCenter)
    {
        // Adding OTs for each face of the tetrahedron.
        AddOtForFace(vecTetA, vecTetB, vecTetC, vecTetD, vecSphCenter);
        AddOtForFace(vecTetB, vecTetC, vecTetD, vecTetA, vecSphCenter);
        AddOtForFace(vecTetC, vecTetD, vecTetA, vecTetB, vecSphCenter);
        AddOtForFace(vecTetD, vecTetA, vecTetB, vecTetC, vecSphCenter);

        // Calculating OT signs.
        for (int idf = 0; idf < 4; ++idf)
            for (int idl = 0; idl < 3; ++idl)
            {
                int ids = 3 * idf + idl;
                int idp = 2 * ids;
                int idm = idp + 1;

                obsTetSgn.push_back(
                    LUV::Dot(obsTet[idp].prdA, dirN[idf]) *
                    LUV::Dot(obsTet[idp].prdF, dirL[ids]) *
                    LUV::Dot(obsTet[idp].prdD, dirU[ids])
                    );

                obsTetSgn.push_back(
                    -1 *
                    LUV::Dot(obsTet[idm].prdA, dirN[idf]) *
                    LUV::Dot(obsTet[idm].prdF, dirL[ids]) *
                    LUV::Dot(obsTet[idm].prdD, dirU[ids])
                    );
            }
    }

    // Solid angle subtended by tetrahedron, as a function of sphere radius.
    double GetSolidAngle(double radius)
    {
        double solidAngle = 0;
        for (int idx = 0; idx < 24; ++idx)
        {
            double solidAngleOt = obsTet[idx].GetSolidAngle(radius) * obsTetSgn[idx];
            solidAngle += std::isnan(solidAngleOt) ? 0 : solidAngleOt;
        }
        return solidAngle;
    }

    // Surface area subtended by tetrahedron, as a function of sphere radius.
    double GetSurfaceArea(double radius)
    {
        return GetSolidAngle(radius) * radius * radius;
    }

    // Sphere-tetrahedron intersection volume, as a function of sphere radius.
    double GetVolume(double radius)
    {
        double volume = 0;
        for (int idx = 0; idx < 24; ++idx)
        {
            double volumeOt = obsTet[idx].GetVolume(radius) * obsTetSgn[idx];
            volume += std::isnan(volumeOt) ? 0 : volumeOt;
        }
        return volume;
    }

private:

    std::vector<ObservationTetrahedron> obsTet; //24 in total
    std::vector<double> obsTetSgn;

    std::vector<Vec3> dirN;
    std::vector<Vec3> dirU;
    std::vector<Vec3> dirL;

    void AddOtForEdge(const Vec3& vecM, const Vec3& vecP, const Vec3& vecT, const Vec3& vecR)
    {
        Vec3 PmM = vecP - vecM;
        dirL.push_back(PmM / LUV::Length(PmM));
        Vec3 vecU = vecT - LUV::ProjLine(vecT, vecM, vecP);
        dirU.push_back(vecU / LUV::Length(vecU));
        Vec3 vecA = LUV::ProjPlane(vecR, vecM, LUV::PlaneNormal(vecM, vecP, vecT));
        Vec3 vecB = LUV::ProjLine(vecA, vecM, vecP);
        obsTet.push_back(ObservationTetrahedron(vecR, vecA, vecB, vecP));
        obsTet.push_back(ObservationTetrahedron(vecR, vecA, vecB, vecM));
    }

    void AddOtForFace(const Vec3& vecA, const Vec3& vecB, const Vec3& vecC, const Vec3& vecU,
                      const Vec3& vecR)
    {
        Vec3 vecN = vecU - LUV::ProjPlane(vecU, vecA, LUV::PlaneNormal(vecA, vecB, vecC));
        dirN.push_back(vecN / LUV::Length(vecN));
        AddOtForEdge(vecA, vecB, vecC, vecR);
        AddOtForEdge(vecB, vecC, vecA, vecR);
        AddOtForEdge(vecC, vecA, vecB, vecR);
    }

};

// An example usage...
int main()
{
    // Tetrahedron with a volume of 1000
    Vec3 vecTetA(0, 0, 0);
    Vec3 vecTetB(10, 0, 0);
    Vec3 vecTetC(0, 20, 0);
    Vec3 vecTetD(0, 0, 30);

    // Center of the sphere
    Vec3 vecSphCenter(0, 0, 0);

    // Intersection class
    SphereTetrahedronIntersection testIntersection(vecTetA, vecTetB, vecTetC, vecTetD,
                                                   vecSphCenter);

    // Demonstrating that numerical integral of surface area is equal to analytical calculation of volume:
    int stepCount = 10000;
    double radiusStart = 0;
    double radiusEnd = 30;
    double radiusDelta = (radiusEnd - radiusStart) / stepCount;
    double volumeNumerical = 0;
    for (double radius = radiusStart; radius < radiusEnd; radius += radiusDelta)
        volumeNumerical += testIntersection.GetSurfaceArea(radius) * radiusDelta;
    double volumeAnalytical = testIntersection.GetVolume(radiusEnd);

    // These 2 values must be almost equal:
    std::cout << volumeAnalytical << ", " << volumeNumerical << std::endl;

    return 0;
}

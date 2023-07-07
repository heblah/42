/*
  Warnings:

  - You are about to drop the column `option2FA` on the `User` table. All the data in the column will be lost.
  - You are about to drop the column `userName` on the `User` table. All the data in the column will be lost.
  - Added the required column `doubleAuth` to the `User` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "User" DROP COLUMN "option2FA",
DROP COLUMN "userName",
ADD COLUMN     "doubleAuth" TEXT NOT NULL,
ADD COLUMN     "username" TEXT;

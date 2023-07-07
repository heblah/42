/*
  Warnings:

  - You are about to drop the column `banExpiration` on the `punishment` table. All the data in the column will be lost.
  - You are about to drop the column `banned` on the `punishment` table. All the data in the column will be lost.
  - You are about to drop the column `kickExpiration` on the `punishment` table. All the data in the column will be lost.
  - You are about to drop the column `kicked` on the `punishment` table. All the data in the column will be lost.
  - You are about to drop the column `muteExpiration` on the `punishment` table. All the data in the column will be lost.
  - You are about to drop the column `muted` on the `punishment` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "punishment" DROP COLUMN "banExpiration",
DROP COLUMN "banned",
DROP COLUMN "kickExpiration",
DROP COLUMN "kicked",
DROP COLUMN "muteExpiration",
DROP COLUMN "muted",
ADD COLUMN     "punishmentExpiration" TIMESTAMP(3),
ADD COLUMN     "type" TEXT NOT NULL DEFAULT 'none';
